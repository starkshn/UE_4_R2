// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyStatComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnHPChanged);

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
	void SetHP(int32 NewHP);
	void OnAttacked(float DamageAmount);

	int32 GetLevel() { return Level; }
	int32 GetAttack() { return Attack; }
	int32 GetHP() { return HP; }
	int32 GetMaxHP() { return MaxHP; }
	float GetHpRatio() { return HP / (float)MaxHP; }

private:
	UPROPERTY(EditAnywhere, Category = Stat, meta = (AllowPrivateAccess = true))
	int32 Level;

	UPROPERTY(EditAnywhere, Category = Stat, meta = (AllowPrivateAccess = true))
	int32 Attack;

	UPROPERTY(EditAnywhere, Category = Stat, meta = (AllowPrivateAccess = true))
	int32 HP;

	UPROPERTY(EditAnywhere, Category = Stat, meta = (AllowPrivateAccess = true))
	int32 MaxHP;

public:
	FOnHPChanged OnHPChanged;


};
