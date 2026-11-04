// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCommonButtonWidget.h"
#include "Components/Button.h"

// MVVM
#include "View/MVVMView.h"
#include "MVVMSubsystem.h"
#include "MVVMViewModelBase.h"

UTestCommonButtonWidget::UTestCommonButtonWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// 初期化(CreateWidgetで呼ばれる)
bool UTestCommonButtonWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}

	// ボタンを取得
	Button = GetButtonInstance();

	// ボタンにコールバックを登録
	if (IsValid(Button))
	{
		Button->OnClicked.AddDynamic(this, &UTestCommonButtonWidget::OnButtonClicked);
	}

	return true;
}

UButton* UTestCommonButtonWidget::GetButton()
{
	return Button;
}

UMVVMViewModelBase* UTestCommonButtonWidget::GetViewModel(const FName& InViewModelName)
{
	// ViewModelを取得
	if (UMVVMView* view = UMVVMSubsystem::GetViewFromUserWidget(this))
	{
		if (UMVVMViewModelBase* viewModel = Cast<UMVVMViewModelBase>(view->GetViewModel(InViewModelName).GetObject()))
		{
			return viewModel;
		}
	}

	return nullptr;
}

void UTestCommonButtonWidget::OnButtonClicked()
{
	if (!IsValid(ButtonViewModel))
	{
		FName viewModelName = TEXT("CommonButtonViewModel");
		ButtonViewModel = Cast<UTestCommonButtonViewModel>(GetViewModel(viewModelName));
	}

	if (IsValid(ButtonViewModel))
	{
		// 外部から設定したコールバックを呼び出す
		ButtonViewModel->OnClickedDelegate.Broadcast();
	}
}
