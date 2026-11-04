// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "TestManager.generated.h"


// Model
UCLASS(BlueprintType)
class MVVMTEST_API UTestManager : public UObject
{
	GENERATED_BODY()
	
public:	
	UTestManager(const FObjectInitializer& ObjectInitializer);

protected:

	UPROPERTY(Transient)
	TObjectPtr<class UTestCommonButtonViewModel> ButtonViewModel;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UTestCommonButtonViewModel>> ButtonViewModelList;

public:

	UFUNCTION(BlueprintCallable)
	void CreateCommonButtonWidget(TSubclassOf<class UUserWidget> InWidgetClass);

	UFUNCTION(BlueprintCallable)
	void SetupButtonList(TSubclassOf<class UUserWidget> InWidgetClass);

protected:

	UFUNCTION()
	void OnCommonButtonClicked(int32 InValue);

};


//// Model
//UCLASS(BlueprintType)
//class MVVMTEST_API UTestManager : public UObject
//{
//	GENERATED_BODY()
//
//public:
//	UTestManager(const FObjectInitializer& ObjectInitializer);
//
//protected:
//
//	UPROPERTY(Transient)
//	TObjectPtr<class UTestCommonButtonViewModel> ButtonViewModel;
//
//public:
//
//	UFUNCTION(BlueprintCallable)
//	void CreateCommonButtonWidget(TSubclassOf<class UUserWidget> InWidgetClass);
//
//protected:
//
//	UFUNCTION(BlueprintCallable)
//	void OnCommonButtonClicked();
//
//};

