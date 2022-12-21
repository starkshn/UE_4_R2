// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_ServiceTarget.h"
#include "MyAIController.h"
#include "MyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"

// TickNode�� ȣ���� �ֱ⸦ �����ֱ� ���� ������
UBTService_ServiceTarget::UBTService_ServiceTarget()
{
	NodeName = TEXT("SearchTarget");
	Interval = 1.0f;
}

// �ֱⰡ ���� ������
void UBTService_ServiceTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	// CurrentPawn :: ���� �� AI�� �����ϴ� ��ü
	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (CurrentPawn == nullptr) return;

	UWorld* World = CurrentPawn->GetWorld();
	FVector Center = CurrentPawn->GetActorLocation();
	float SearchRadius = 400.f;

	if (World == nullptr) return;

	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams QueryParams(NAME_None, false, CurrentPawn);

	bool bResult = World->OverlapMultiByChannel
	(
		OverlapResults,
		Center,
		FQuat::Identity,
		ECollisionChannel::ECC_EngineTraceChannel2,
		FCollisionShape::MakeSphere(SearchRadius),
		QueryParams
	);

	if (bResult)
	{
		// Targetã�� ���
		for (auto& OverlapResult : OverlapResults)
		{
			AMyCharacter* MyCharacter = Cast<AMyCharacter>(OverlapResult.GetActor());

			// ��¥ Player�� �´��� ���� üũ
			if (MyCharacter && MyCharacter->GetController()->IsPlayerController())
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), MyCharacter);

				// 16�� ���е���
				DrawDebugSphere(World, Center, SearchRadius, 16, FColor::Green, false, 0.3f);

				return;
			}
		}
	}
	else 
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), nullptr);
	}

	DrawDebugSphere(World, Center, SearchRadius, 16, FColor::Red, false, 0.3f);

}
