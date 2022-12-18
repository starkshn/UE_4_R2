// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyStatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE4_R_API UMyStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void InitializeComponent() override;
		
public:
	void SetLevel(int32 Level);
	void OnAttacked(float DamageAmount);

	int32 GetLevel() { return Level; }
	int32 GetAttack() { return Attack; }
	int32 GetHP() { return HP; }

private:
	UPROPERTY(EditAnywhere, Category = Stat, meta = (AllowPrivateAccess = true))
	int32 Level;

	UPROPERTY(EditAnywhere, Category = Stat, meta = (AllowPrivateAccess = true))
	int32 Attack;

	UPROPERTY(EditAnywhere, Category = Stat, meta = (AllowPrivateAccess = true))
	int32 HP;

};
