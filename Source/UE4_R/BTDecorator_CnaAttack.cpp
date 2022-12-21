// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_CnaAttack.h"
#include "MyAIController.h"
#include "MyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTDecorator_CnaAttack::UBTDecorator_CnaAttack()
{
    NodeName = TEXT("CanAttack");
}

bool UBTDecorator_CnaAttack::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);
    
    // 인공지능 실행하는 Pawn찾기
    auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
    if (CurrentPawn == nullptr) return false;

    auto Target = Cast<AMyCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(TEXT("Target"))));

    if (Target == nullptr) return false;

    return bResult && Target->GetDistanceTo(CurrentPawn) <= 200.f;
}
