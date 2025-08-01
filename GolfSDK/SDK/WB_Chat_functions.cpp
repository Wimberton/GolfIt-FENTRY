#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: WB_Chat

#include "Basic.hpp"

#include "WB_Chat_classes.hpp"
#include "WB_Chat_parameters.hpp"


namespace SDK
{

// Function WB_Chat.WB_Chat_C.OnFocusReceived
// (BlueprintCosmetic, Event, Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// struct FFocusEvent                      InFocusEvent                                           (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor)
// struct FEventReply                      ReturnValue                                            (Parm, OutParm, ReturnParm)

struct FEventReply UWB_Chat_C::OnFocusReceived(const struct FGeometry& MyGeometry, const struct FFocusEvent& InFocusEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Chat_C", "OnFocusReceived");

	Params::WB_Chat_C_OnFocusReceived Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.InFocusEvent = std::move(InFocusEvent);

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function WB_Chat.WB_Chat_C.AddStyleToString
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class FString                           Text                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
// struct FLinearColor                     Color                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class FString                           StyledText                                             (Parm, OutParm, ZeroConstructor, HasGetValueTypeHash)

void UWB_Chat_C::AddStyleToString(const class FString& Text, const struct FLinearColor& Color, class FString* StyledText)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Chat_C", "AddStyleToString");

	Params::WB_Chat_C_AddStyleToString Parms{};

	Parms.Text = std::move(Text);
	Parms.Color = std::move(Color);

	UObject::ProcessEvent(Func, &Parms);

	if (StyledText != nullptr)
		*StyledText = std::move(Parms.StyledText);
}


// Function WB_Chat.WB_Chat_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UWB_Chat_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Chat_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_Chat.WB_Chat_C.AddPlainMessage
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           Text                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
// class AGolfItBasePlayerState*           SendingPlayer                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Chat_C::AddPlainMessage(const class FString& Text, class AGolfItBasePlayerState* SendingPlayer)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Chat_C", "AddPlainMessage");

	Params::WB_Chat_C_AddPlainMessage Parms{};

	Parms.Text = std::move(Text);
	Parms.SendingPlayer = SendingPlayer;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Chat.WB_Chat_C.OpenLog
// (BlueprintCallable, BlueprintEvent)

void UWB_Chat_C::OpenLog()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Chat_C", "OpenLog");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_Chat.WB_Chat_C.CloseLog
// (BlueprintCallable, BlueprintEvent)

void UWB_Chat_C::CloseLog()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Chat_C", "CloseLog");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_Chat.WB_Chat_C.AddUserMessage
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           Message                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
// class AGolfItBasePlayerState*           SendingPlayerState                                     (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Chat_C::AddUserMessage(const class FString& Message, const class AGolfItBasePlayerState* SendingPlayerState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Chat_C", "AddUserMessage");

	Params::WB_Chat_C_AddUserMessage Parms{};

	Parms.Message = std::move(Message);
	Parms.SendingPlayerState = SendingPlayerState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Chat.WB_Chat_C.BndEvt__WB_Chat_TextBox_Chat_K2Node_ComponentBoundEvent_0_OnEditableTextBoxCommittedEvent__DelegateSignature
// (HasOutParams, BlueprintEvent)
// Parameters:
// class FText                             Text                                                   (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// ETextCommit                             CommitMethod                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Chat_C::BndEvt__WB_Chat_TextBox_Chat_K2Node_ComponentBoundEvent_0_OnEditableTextBoxCommittedEvent__DelegateSignature(const class FText& Text, ETextCommit CommitMethod)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Chat_C", "BndEvt__WB_Chat_TextBox_Chat_K2Node_ComponentBoundEvent_0_OnEditableTextBoxCommittedEvent__DelegateSignature");

	Params::WB_Chat_C_BndEvt__WB_Chat_TextBox_Chat_K2Node_ComponentBoundEvent_0_OnEditableTextBoxCommittedEvent__DelegateSignature Parms{};

	Parms.Text = std::move(Text);
	Parms.CommitMethod = CommitMethod;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Chat.WB_Chat_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWB_Chat_C::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Chat_C", "PreConstruct");

	Params::WB_Chat_C_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Chat.WB_Chat_C.SetChatbarVisibility
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// ESlateVisibility                        InVisibility                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Chat_C::SetChatbarVisibility(ESlateVisibility InVisibility)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Chat_C", "SetChatbarVisibility");

	Params::WB_Chat_C_SetChatbarVisibility Parms{};

	Parms.InVisibility = InVisibility;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Chat.WB_Chat_C.AddColoredMessage
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           Message                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
// struct FLinearColor                     Color                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Chat_C::AddColoredMessage(const class FString& Message, const struct FLinearColor& Color)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Chat_C", "AddColoredMessage");

	Params::WB_Chat_C_AddColoredMessage Parms{};

	Parms.Message = std::move(Message);
	Parms.Color = std::move(Color);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Chat.WB_Chat_C.PlayerJoined
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class AGolfItBasePlayerState*           PlayerState                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Chat_C::PlayerJoined(class AGolfItBasePlayerState* PlayerState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Chat_C", "PlayerJoined");

	Params::WB_Chat_C_PlayerJoined Parms{};

	Parms.PlayerState = PlayerState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Chat.WB_Chat_C.OnAddedToFocusPath
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// struct FFocusEvent                      InFocusEvent                                           (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor)

void UWB_Chat_C::OnAddedToFocusPath(const struct FFocusEvent& InFocusEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Chat_C", "OnAddedToFocusPath");

	Params::WB_Chat_C_OnAddedToFocusPath Parms{};

	Parms.InFocusEvent = std::move(InFocusEvent);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Chat.WB_Chat_C.PlayerReputationRecieved
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    RequestFailed                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Banned                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWB_Chat_C::PlayerReputationRecieved(bool RequestFailed, bool Banned)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Chat_C", "PlayerReputationRecieved");

	Params::WB_Chat_C_PlayerReputationRecieved Parms{};

	Parms.RequestFailed = RequestFailed;
	Parms.Banned = Banned;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Chat.WB_Chat_C.OnRemovedFromFocusPath
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// struct FFocusEvent                      InFocusEvent                                           (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor)

void UWB_Chat_C::OnRemovedFromFocusPath(const struct FFocusEvent& InFocusEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Chat_C", "OnRemovedFromFocusPath");

	Params::WB_Chat_C_OnRemovedFromFocusPath Parms{};

	Parms.InFocusEvent = std::move(InFocusEvent);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Chat.WB_Chat_C.CheckTextFocusChanged
// (BlueprintCallable, BlueprintEvent)

void UWB_Chat_C::CheckTextFocusChanged()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Chat_C", "CheckTextFocusChanged");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_Chat.WB_Chat_C.ExecuteUbergraph_WB_Chat
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Chat_C::ExecuteUbergraph_WB_Chat(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Chat_C", "ExecuteUbergraph_WB_Chat");

	Params::WB_Chat_C_ExecuteUbergraph_WB_Chat Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Chat.WB_Chat_C.ChatTextFocusChanged__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWB_Chat_C*                       ChatWidget                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    NewFocus                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWB_Chat_C::ChatTextFocusChanged__DelegateSignature(class UWB_Chat_C* ChatWidget, bool NewFocus)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Chat_C", "ChatTextFocusChanged__DelegateSignature");

	Params::WB_Chat_C_ChatTextFocusChanged__DelegateSignature Parms{};

	Parms.ChatWidget = ChatWidget;
	Parms.NewFocus = NewFocus;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Chat.WB_Chat_C.OnMessageSent__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWB_Chat_C*                       Chat                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class FText                             Message                                                (BlueprintVisible, BlueprintReadOnly, Parm)

void UWB_Chat_C::OnMessageSent__DelegateSignature(class UWB_Chat_C* Chat, const class FText& Message)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Chat_C", "OnMessageSent__DelegateSignature");

	Params::WB_Chat_C_OnMessageSent__DelegateSignature Parms{};

	Parms.Chat = Chat;
	Parms.Message = std::move(Message);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Chat.WB_Chat_C.BP_GetDesiredFocusTarget
// (Event, Protected, HasOutParams, BlueprintCallable, BlueprintEvent, Const)
// Parameters:
// class UWidget*                          ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

class UWidget* UWB_Chat_C::BP_GetDesiredFocusTarget() const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Chat_C", "BP_GetDesiredFocusTarget");

	Params::WB_Chat_C_BP_GetDesiredFocusTarget Parms{};

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}

}

