// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterWidget.h"
#include "MyStatComponent.h"
#include "Components/ProgressBar.h"

void UMyCharacterWidget::BindHP(UMyStatComponent* StatComp)
{
	// ������� ProgressBar�ٸ� ���
	// PB_HpBar123 = Cast<UProgressBar>(GetWidgetFromName(TEXT("PB_HpBar")));

	CurrentStatComp = StatComp;
	StatComp->OnHPChanged.AddUObject(this, &UMyCharacterWidget::UpdateHP);
}

void UMyCharacterWidget::UpdateHP()
{
	if (CurrentStatComp.IsValid())
		PB_HpBar->SetPercent(CurrentStatComp->GetHpRatio());	
}


