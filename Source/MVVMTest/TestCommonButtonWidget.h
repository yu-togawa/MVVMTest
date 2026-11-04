// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MVVMViewModelBase.h"

#include "TestCommonButtonWidget.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnCommonButtonClickedEvent)

class UTestCommonButtonViewModel;

// View
UCLASS(BlueprintType)
class MVVMTEST_API UTestCommonButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:	
	UTestCommonButtonWidget(const FObjectInitializer& ObjectInitializer);

	//--------------------------------------------------------------------------
	// 初期化(CreateWidgetで呼ばれる)
	//--------------------------------------------------------------------------
	virtual bool Initialize() override;

	UFUNCTION(BlueprintCallable)
	void OnButtonClicked();

	UFUNCTION(BlueprintCallable)
	class UMVVMViewModelBase* GetViewModel(const FName& InViewModelName);

	UFUNCTION(BlueprintCallable)
	UButton* GetButton();

protected:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	UButton* GetButtonInstance();

protected:

	// ボタン
	UPROPERTY(Transient)
	TObjectPtr<UButton> Button;

	// ViewModel
	UPROPERTY(Transient)
	TObjectPtr<UTestCommonButtonViewModel> ButtonViewModel;
};

// ViewModel
UCLASS(BlueprintType, Blueprintable)
class UTestCommonButtonViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:

	// Setter
	void SetItemName(const FText& NewVal) { UE_MVVM_SET_PROPERTY_VALUE(ItemName, NewVal); }
	// Getter
	const FText& GetItemName() const { return ItemName; }

public:

	// クリックされた時のデリゲート（外部からBroadcast自由にできないようにする）
	FOnCommonButtonClickedEvent OnClickedDelegate;

protected:

	// 項目名
	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter, Getter)
	FText ItemName;
};

