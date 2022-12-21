// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_ServiceTarget.h"
#include "MyAIController.h"
#include "MyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"

// TickNode를 호출할 주기를 정해주기 위한 생성자
UBTService_ServiceTarget::UBTService_ServiceTarget()
{
	NodeName = TEXT("SearchTarget");
	Interval = 1.0f;
}

// 주기가 정해 져야함
void UBTService_ServiceTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	// CurrentPawn :: 현재 이 AI를 실행하는 주체
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
		// Target찾은 경우
		for (auto& OverlapResult : OverlapResults)
		{
			AMyCharacter* MyCharacter = Cast<AMyCharacter>(OverlapResult.GetActor());

			// 진짜 Player가 맞는지 이중 체크
			if (MyCharacter && MyCharacter->GetController()->IsPlayerController())
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), MyCharacter);

				// 16은 정밀도임
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
