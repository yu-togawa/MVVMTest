// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MVVMViewModelBase.h"

#include "TestWidget.generated.h"

class UTestCommonButtonViewModel;
class UTestCommonButtonWidget;

// WidgetÅiViewÅj
UCLASS(BlueprintType)
class MVVMTEST_API UTestWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:	
	UTestWidget(const FObjectInitializer& ObjectInitializer);

	//--------------------------------------------------------------------------
	// èâä˙âª(CreateWidgetÇ≈åƒÇŒÇÍÇÈ)
	//--------------------------------------------------------------------------
	virtual bool Initialize() override;

	UFUNCTION(BlueprintCallable)
	TArray<UTestCommonButtonWidget*> GetButtonList();

protected:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	TArray<UTestCommonButtonWidget*> GetButtonInstanceList();

	UPROPERTY(Transient)
	TArray<TObjectPtr<UTestCommonButtonWidget>> ButtonList;
};

