// Fill out your copyright notice in the Description page of Project Settings.


#include "TestManager.h"
#include "TestWidgetViewModel.h"

// UI
#include "MVVMTest/TestCommonButtonWidget.h"
#include "MVVMTest/TestCommonButton.h"
#include "MVVMTest/TestWidget.h"

// MVVM
#include "View/MVVMView.h"
#include "MVVMSubsystem.h"


// Sets default values
UTestManager::UTestManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UTestManager::CreateCommonButtonWidget(TSubclassOf<UUserWidget> InWidgetClass)
{
	// World取得
	UWorld* world = GetWorld();

	// Widget生成
	FName widgetName = TEXT("TestCommonButtonWidget");
	TObjectPtr<UUserWidget> widget = UUserWidget::CreateWidgetInstance(*world, InWidgetClass, widgetName);
	if (!IsValid(widget))
		return;

	// Viewportに追加
	widget->AddToViewport();

	// ViewModel生成
	FName viewModelName = TEXT("CommonButtonViewModel");
	ButtonViewModel = NewObject<UTestCommonButtonViewModel>(this, viewModelName);

	// ViewModelにパラメータを設定
	FString itemName = TEXT("Button");
	ButtonViewModel->SetItemName(FText::FromString(itemName));
	ButtonViewModel->OnClickedDelegate.AddUObject(this, &UTestManager::OnCommonButtonClicked, 1000);

	// ViewModelを設定
	UMVVMView* view = UMVVMSubsystem::GetViewFromUserWidget(widget);
	if (IsValid(view))
	{
		view->SetViewModel(viewModelName, ButtonViewModel);
	}
}

void UTestManager::SetupButtonList(TSubclassOf<UUserWidget> InWidgetClass)
{
	// World取得
	UWorld* world = GetWorld();

	// Widget生成
	FName widgetName = TEXT("TestWidget");
	TObjectPtr<UTestWidget> testWidget = Cast<UTestWidget>(UUserWidget::CreateWidgetInstance(*world, InWidgetClass, widgetName));
	if (!IsValid(testWidget))
		return;

	// Viewportに追加
	testWidget->AddToViewport();

	// ボタンリストを取得
	TArray<UTestCommonButtonWidget*> commonButtonList = testWidget->GetButtonList();
	for (int i = 0;i < commonButtonList.Num();++i)
	{
		UTestCommonButtonWidget* commonButton = commonButtonList[i];

		// ViewModel生成
		FName viewModelName = TEXT("CommonButtonViewModel");
		UTestCommonButtonViewModel* newViewModel = NewObject<UTestCommonButtonViewModel>(commonButton, viewModelName);
		ButtonViewModelList.Add(newViewModel);

		// ViewModelにパラメータを設定
		FString itemName = TEXT("Button_") + FString::FromInt(i);
		newViewModel->SetItemName(FText::FromString(itemName));
		newViewModel->OnClickedDelegate.AddUObject(this, &UTestManager::OnCommonButtonClicked, i);

		// ViewModelを設定
		UMVVMView* view = UMVVMSubsystem::GetViewFromUserWidget(commonButton);
		if (IsValid(view))
		{
			view->SetViewModel(viewModelName, newViewModel);
		}
	}
}

// ボタンが押された時に呼ばれる処理
void UTestManager::OnCommonButtonClicked(int32 InValue)
{
	UE_LOG(LogTemp, Log, TEXT("UTestManager::OnCommonButtonClicked : Hoge![%d]"), InValue);
}

