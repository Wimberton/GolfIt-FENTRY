#include "DLLAuth.h"
#include <Windows.h>
#include <winhttp.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <intrin.h>
#include <comdef.h>
#include <Wbemidl.h>
#include <iphlpapi.h>

#pragma comment(lib, "winhttp.lib")
#pragma comment(lib, "wbemuuid.lib")
#pragma comment(lib, "iphlpapi.lib")

DLLAuth::DLLAuth(const std::string& license, const std::string& ver)
    : licenseKey(license), version(ver), apiUrl("https://api.fentry.org"), hSession(nullptr), hConnect(nullptr) {
    hwid = GetHardwareID();
    InitializeHTTP();
}

DLLAuth::~DLLAuth() {
    Stop();
    CleanupHTTP();
}

void DLLAuth::InitializeHTTP() {
    // Initialize WinHTTP
    hSession = WinHttpOpen(L"GolfItFentry DLL/1.0", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    if (hSession) {
        hConnect = WinHttpConnect(hSession, L"api.fentry.org", INTERNET_DEFAULT_HTTPS_PORT, 0);
    }
}

void DLLAuth::CleanupHTTP() {
    if (hConnect) {
        WinHttpCloseHandle(hConnect);
        hConnect = nullptr;
    }
    if (hSession) {
        WinHttpCloseHandle(hSession);
        hSession = nullptr;
    }
}

std::string DLLAuth::GetHardwareID() {
    std::string hwid;
    
    // Get CPU ID
    int cpuInfo[4];
    __cpuid(cpuInfo, 0);
    char cpuString[13];
    memcpy(cpuString, &cpuInfo[1], 4);
    memcpy(cpuString + 4, &cpuInfo[3], 4);
    memcpy(cpuString + 8, &cpuInfo[2], 4);
    cpuString[12] = '\0';
    
    // Get MAC address
    std::string macAddress;
    PIP_ADAPTER_INFO adapterInfo;
    PIP_ADAPTER_INFO adapter = nullptr;
    DWORD dwRetVal = 0;
    ULONG ulOutBufLen = sizeof(IP_ADAPTER_INFO);
    
    adapterInfo = (IP_ADAPTER_INFO*)malloc(sizeof(IP_ADAPTER_INFO));
    if (adapterInfo == nullptr) {
        return "UNKNOWN_HWID";
    }
    
    if (GetAdaptersInfo(adapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW) {
        free(adapterInfo);
        adapterInfo = (IP_ADAPTER_INFO*)malloc(ulOutBufLen);
        if (adapterInfo == nullptr) {
            return "UNKNOWN_HWID";
        }
    }
    
    if ((dwRetVal = GetAdaptersInfo(adapterInfo, &ulOutBufLen)) == NO_ERROR) {
        adapter = adapterInfo;
        if (adapter) {
            std::stringstream ss;
            for (int i = 0; i < adapter->AddressLength; i++) {
                ss << std::hex << (int)adapter->Address[i];
                if (i < adapter->AddressLength - 1) {
                    ss << ":";
                }
            }
            macAddress = ss.str();
        }
    }
    
    if (adapterInfo) {
        free(adapterInfo);
    }
    
    // Combine CPU and MAC for HWID
    hwid = std::string(cpuString) + "_" + macAddress;
    
    // Create a simple hash to make it shorter
    std::hash<std::string> hasher;
    size_t hashValue = hasher(hwid);
    
    std::stringstream finalHwid;
    finalHwid << std::hex << hashValue;
    
    return finalHwid.str();
}

std::string DLLAuth::HttpPost(const std::string& endpoint, const std::string& jsonData) {
    if (!hConnect) {
        LogMessage("[DLL Auth] HTTP connection not available");
        return "";
    }
    
    std::wstring wEndpoint(endpoint.begin(), endpoint.end());
    HINTERNET hRequest = WinHttpOpenRequest(hConnect, L"POST", wEndpoint.c_str(), NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, WINHTTP_FLAG_SECURE);
    
    if (!hRequest) {
        LogMessage("[DLL Auth] Failed to create HTTP request");
        return "";
    }
    
    // Set headers
    std::wstring headers = L"Content-Type: application/json\r\n";
    WinHttpAddRequestHeaders(hRequest, headers.c_str(), -1, WINHTTP_ADDREQ_FLAG_ADD);
    
    // Convert JSON data to wide string
    std::wstring wJsonData(jsonData.begin(), jsonData.end());
    
    // Send request
    BOOL bResults = WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0, (LPVOID)jsonData.c_str(), jsonData.length(), jsonData.length(), 0);
    
    std::string response;
    if (bResults) {
        bResults = WinHttpReceiveResponse(hRequest, NULL);
        
        if (bResults) {
            DWORD dwSize = 0;
            DWORD dwDownloaded = 0;
            
            do {
                dwSize = 0;
                if (!WinHttpQueryDataAvailable(hRequest, &dwSize)) {
                    break;
                }
                
                std::vector<char> buffer(dwSize + 1);
                ZeroMemory(buffer.data(), dwSize + 1);
                
                if (!WinHttpReadData(hRequest, buffer.data(), dwSize, &dwDownloaded)) {
                    break;
                }
                
                response.append(buffer.data(), dwDownloaded);
                
            } while (dwSize > 0);
        }
    }
    
    WinHttpCloseHandle(hRequest);
    return response;
}

std::string DLLAuth::ParseJsonString(const std::string& json, const std::string& key) {
    std::string searchKey = "\"" + key + "\":\"";
    size_t pos = json.find(searchKey);
    if (pos == std::string::npos) {
        return "";
    }
    
    pos += searchKey.length();
    size_t endPos = json.find("\"", pos);
    if (endPos == std::string::npos) {
        return "";
    }
    
    return json.substr(pos, endPos - pos);
}

bool DLLAuth::ParseJsonBool(const std::string& json, const std::string& key) {
    std::string searchKey = "\"" + key + "\":";
    size_t pos = json.find(searchKey);
    if (pos == std::string::npos) {
        return false;
    }
    
    pos += searchKey.length();
    return json.substr(pos, 4) == "true";
}

void DLLAuth::LogMessage(const std::string& message) {
    std::cout << message << std::endl;
    OutputDebugStringA((message + "\n").c_str());
}

void DLLAuth::OpenBrowserWindow(const std::string& url) {
    std::string command = "start \"\" \"" + url + "\"";
    system(command.c_str());
}

bool DLLAuth::Authenticate() {
    LogMessage("[DLL Auth] Starting authentication process...");
    
    // Step 1: Initial authentication
    std::string jsonData = "{\"licenseKey\":\"" + licenseKey + "\",\"hwid\":\"" + hwid + "\",\"version\":\"" + version + "\"}";
    std::string response = HttpPost("/dll/authenticate", jsonData);
    
    if (response.empty()) {
        LogMessage("[DLL Auth] Failed to connect to authentication server");
        return false;
    }
    
    // Check if authentication was successful
    bool success = ParseJsonBool(response, "success");
    if (!success) {
        std::string errorMsg = ParseJsonString(response, "message");
        std::string errorCode = ParseJsonString(response, "code");
        LogMessage("[DLL Auth] Authentication failed: " + errorMsg + " (Code: " + errorCode + ")");
        return false;
    }
    
    // Extract session ID and redirect URL
    sessionId = ParseJsonString(response, "sessionId");
    std::string redirectUrl = ParseJsonString(response, "redirectUrl");
    
    if (sessionId.empty() || redirectUrl.empty()) {
        LogMessage("[DLL Auth] Failed to parse session information from response");
        return false;
    }
    
    LogMessage("[DLL Auth] Authentication successful, session ID: " + sessionId);
    LogMessage("[DLL Auth] Opening browser window for terms acceptance...");
    
    // Step 2: Open browser window
    OpenBrowserWindow(redirectUrl);
    
    // Step 3: Start polling for terms acceptance
    shouldStop = false;
    authenticationComplete = false;
    authenticationSuccess = false;
    
    pollingThread = std::thread(&DLLAuth::PollTermsStatus, this);
    
    // Wait for authentication to complete (max 60 seconds)
    auto startTime = std::chrono::steady_clock::now();
    auto timeout = std::chrono::seconds(60);
    
    while (!authenticationComplete.load() && !shouldStop.load()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        
        auto currentTime = std::chrono::steady_clock::now();
        if (currentTime - startTime > timeout) {
            LogMessage("[DLL Auth] Authentication timeout - user did not accept terms within 60 seconds");
            Stop();
            return false;
        }
    }
    
    // Wait for polling thread to finish
    if (pollingThread.joinable()) {
        pollingThread.join();
    }
    
    bool result = authenticationSuccess.load();
    LogMessage("[DLL Auth] Authentication process completed. Result: " + std::string(result ? "SUCCESS" : "FAILED"));
    
    return result;
}

void DLLAuth::PollTermsStatus() {
    // LogMessage("[DLL Auth] Started polling for terms acceptance (60 second timeout)...");
    
    while (!shouldStop.load()) {
        std::string jsonData = "{\"sessionId\":\"" + sessionId + "\"}";
        std::string response = HttpPost("/dll/check-terms-status", jsonData);
        
        if (!response.empty()) {
            bool success = ParseJsonBool(response, "success");
            if (success) {
                std::string code = ParseJsonString(response, "code");
                
                if (code == "TERMS_ACCEPTED") {
                    LogMessage("[DLL Auth] Terms accepted! DLL can proceed.");
                    authenticationSuccess = true;
                    authenticationComplete = true;
                    return;
                } else if (code == "TERMS_PENDING") {
                    // Continue polling - user hasn't accepted yet
                    // LogMessage("[DLL Auth] Terms still pending...");
                } else {
                    LogMessage("[DLL Auth] Unexpected response code: " + code);
                    break;
                }
            } else {
                std::string errorMsg = ParseJsonString(response, "message");
                std::string errorCode = ParseJsonString(response, "code");
                LogMessage("[DLL Auth] Error checking terms status: " + errorMsg + " (Code: " + errorCode + ")");
                
                // If session is invalid or expired, stop polling
                if (errorCode == "INVALID_SESSION") {
                    break;
                }
            }
        } else {
            LogMessage("[DLL Auth] Failed to connect to server during terms polling");
        }
        
        // Wait 2 seconds before next poll
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    
    LogMessage("[DLL Auth] Terms polling stopped - user did not accept terms");
    authenticationComplete = true;
    authenticationSuccess = false;
}

void DLLAuth::Stop() {
    shouldStop = true;
    if (pollingThread.joinable()) {
        pollingThread.join();
    }
}

bool DLLAuth::CheckLicenseStatus() {
    if (licenseKey.empty() || hwid.empty()) {
        return false;
    }
    
    std::string jsonData = "{\"licenseKey\":\"" + licenseKey + "\",\"hwid\":\"" + hwid + "\"}";
    std::string response = HttpPost("/dll/check-status", jsonData);
    
    if (response.empty()) {
        return false;
    }
    
    bool success = ParseJsonBool(response, "success");
    if (success) {
        std::string code = ParseJsonString(response, "code");
        return code == "LICENSE_VALID";
    }
    
    return false;
} 