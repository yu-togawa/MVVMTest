// Fill out your copyright notice in the Description page of Project Settings.


#include "TestWidget.h"
#include "Layout/Geometry.h"
#include "Components/Button.h"
#include "MVVMTest/TestCommonButtonWidget.h"

// Sets default values
UTestWidget::UTestWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// 初期化(CreateWidgetで呼ばれる)
bool UTestWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}

	// ボタンリストを取得
	ButtonList = GetButtonInstanceList();

	return true;
}

TArray<UTestCommonButtonWidget*> UTestWidget::GetButtonList()
{
	return ButtonList;
}
