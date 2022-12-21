// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_CnaAttack.generated.h"

/**
 * 
 */
UCLASS()
class UE4_R_API UBTDecorator_CnaAttack : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UBTDecorator_CnaAttack();

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
