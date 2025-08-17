#pragma once

#include <string>
#include <functional>
#include <memory>
#include <thread>
#include <atomic>
#include <chrono>

// Forward declarations
typedef void* HINTERNET;

class DLLAuth {
private:
    std::string licenseKey;
    std::string hwid;
    std::string version;
    std::string apiUrl;
    std::string sessionId;
    std::atomic<bool> authenticationComplete{false};
    std::atomic<bool> authenticationSuccess{false};
    std::atomic<bool> shouldStop{false};
    std::thread pollingThread;
    
    // HTTP client handles
    HINTERNET hSession;
    HINTERNET hConnect;
    
    // Helper methods
    std::string GetHardwareID();
    std::string HttpPost(const std::string& endpoint, const std::string& jsonData);
    std::string ParseJsonString(const std::string& json, const std::string& key);
    bool ParseJsonBool(const std::string& json, const std::string& key);
    void InitializeHTTP();
    void CleanupHTTP();
    void OpenBrowserWindow(const std::string& url);
    void PollTermsStatus();
    void LogMessage(const std::string& message);
    
public:
    DLLAuth(const std::string& license, const std::string& ver = "1.0.0");
    ~DLLAuth();
    
    // Main authentication method
    bool Authenticate();
    
    // Check if authentication is complete and successful
    bool IsAuthenticationComplete() const { return authenticationComplete.load(); }
    bool IsAuthenticationSuccessful() const { return authenticationSuccess.load(); }
    
    // Stop authentication process
    void Stop();
    
    // Periodic license status check for running DLL
    bool CheckLicenseStatus();
    
    // Get current session info
    std::string GetSessionId() const { return sessionId; }
    std::string GetLicenseKey() const { return licenseKey; }
}; 