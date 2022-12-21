// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_ServiceTarget.generated.h"

/**
 * 
 */
UCLASS()
class UE4_R_API UBTService_ServiceTarget : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_ServiceTarget();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;


};
