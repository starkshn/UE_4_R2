// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyCharacterWidget.generated.h"

/**
 * 
 */
UCLASS()
class UE4_R_API UMyCharacterWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void BindHP(class UMyStatComponent* StatComp);

	void UpdateHP();
	

private:
	// Tool과 이름이 같을 경우
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* PB_HpBar;

	// Tool과 이름이 다를경우
	//UPROPERTY(meta = (BindWidget))
	//class UProgressBar* PB_HpBar123;

	TWeakObjectPtr<class UMyStatComponent> CurrentStatComp;	
};
