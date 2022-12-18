// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
	// 언제나 그랫듯이 생성자에서 필요한 오브젝트? 같은것들 로드해준다.
	static ConstructorHelpers::FObjectFinder<UDataTable> DATA(TEXT("DataTable'/Game/Data/StatTable.StatTable'"));

	if (DATA.Succeeded())
		MyStat = DATA.Object;
}

void UMyGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Warning, TEXT("MyGameInstance %d"), GetStatData(1)->Attack);
}

FMyCharacterData* UMyGameInstance::GetStatData(int32 Level)
{
	return MyStat->FindRow<FMyCharacterData>(*FString::FromInt(Level), TEXT(""));
}
