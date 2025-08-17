#pragma once

#include <SDK.hpp>
#include <vector>

namespace SDK {
    inline UEngine* GetEngine() {
        static UEngine* GEngine = nullptr;

        if (!GEngine) {
            for (int i = 0; i < UObject::GObjects->Num(); i++) {
                UObject* Obj = UObject::GObjects->GetByIndex(i);

                if (!Obj)
                    continue;

                if (Obj->IsA(UEngine::StaticClass()) && !Obj->IsDefaultObject()) {
                    GEngine = static_cast<UEngine*>(Obj);
                    break;
                }
            }
        }

        return GEngine;
    }

    inline UWorld* GetWorld() {
        if (const UEngine* Engine = GetEngine()) {
            if (!Engine->GameViewport)
                return nullptr;
            return Engine->GameViewport->World;
        }
        return nullptr;
    }

}

namespace SDKExt {
    // Define FFrame (TheStack)
    using FlowStackType = uint8_t[0x30];
    struct alignas(0x8) FOutParmRec {
        SDK::FProperty* Property;
        uint8_t* PropAddr;
        FOutParmRec* NextOutParm;
    };
    class alignas(0x8) FFrame {
    public:
        uint8_t Pad_FOutputDevice[0x10];
        SDK::UFunction* Node;
        SDK::UObject* Object;
        uint8_t* Code;
        uint8_t* Locals;

        SDK::FProperty* MostRecentProperty;
        uint8_t* MostRecentPropertyAddress;
        uint8_t* MostRecentPropertyContainer;
        FlowStackType FlowStack;
        FFrame* PreviousFrame;
        FOutParmRec* OutParms;
        SDK::FField* PropertyChainForCompiledIn;
        SDK::UFunction* CurrentNativeFunction;
        bool bArrayContextFailed;
    };

    //struct FDelegateHandle
    //{
    //    uint64 ID;
    //};

    //struct FCachedMaxCapacity
    //{
    //    int CachedCapacity;
    //    FDelegateHandle StatChangedEventDelegateHandle;
    //};

    // I am a madlad
    class FUObjectCreateListener
    {
    public:
        virtual ~FUObjectCreateListener() = default;
        virtual void NotifyUObjectCreated(const class SDK::UObject* Object, SDK::int32 Index) = 0;
        virtual void OnUObjectArrayShutdown() = 0;
    };

    class FUObjectDeleteListener
    {
    public:
        virtual ~FUObjectDeleteListener() = default;
        virtual void NotifyUObjectDeleted(const class SDK::UObject* Object, SDK::int32 Index) = 0;
        virtual void OnUObjectArrayShutdown() = 0;
    };

    class UObjectArray
    {
    public:
        static SDK::TArray<FUObjectCreateListener*>* GetCreateArray() {
            return reinterpret_cast<SDK::TArray<FUObjectCreateListener*>*>(SDK::InSDKUtils::GetImageBase() + SDK::Offsets::GObjects + 0x58);
        };
        static SDK::TArray<FUObjectDeleteListener*>* GetDeleteArray() {
            return reinterpret_cast<SDK::TArray<FUObjectDeleteListener*>*>(SDK::InSDKUtils::GetImageBase() + SDK::Offsets::GObjects + 0x68);
        };
        static void AddUObjectCreateListener(FUObjectCreateListener* Listener) {
            auto arr = GetCreateArray();
            if (arr->Max() == 0) {
                SDK::TArray<FUObjectCreateListener*> newArr;
                newArr.Add(Listener);
                *arr = newArr;
            }
            else {
                arr->Add(Listener);
            }
        };
        static void RemoveUObjectCreateListener(FUObjectCreateListener* Listener) {
            auto arr = GetCreateArray();
            for (int i = 0; i < arr->Num(); i++) {
                if ((*arr)[i] == Listener) {
                    arr->Remove(i);
                    break;
                }
            }
        };
        static void AddUObjectDeleteListener(FUObjectDeleteListener* Listener) {
            auto arr = GetDeleteArray();
            if (arr->Max() == 0) {
                SDK::TArray<FUObjectDeleteListener*> newArr;
                newArr.Add(Listener);
                *arr = newArr;
            }
            else {
                arr->Add(Listener);
            }
        };
        static void RemoveUObjectDeleteListener(FUObjectDeleteListener* Listener) {
            auto arr = GetDeleteArray();
            for (int i = 0; i < arr->Num(); i++) {
                if ((*arr)[i] == Listener) {
                    arr->Remove(i);
                    break;
                }
            }
        };
    };

    typedef void* (__fastcall* tFMemMalloc)(unsigned __int64 Count, unsigned int Alignment);
    extern tFMemMalloc native_FMemMalloc;
}