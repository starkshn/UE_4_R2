// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class UE4_R_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Attack();
	void AttackCheck();

	void UpDown(float Value);
	void LeftRight(float Value);
	void Yaw(float Value);

	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

private:
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;
	
	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = "Pawn")
	bool IsAttacking = false;

	// 컴포넌트는 UPROPERTY를 붙여야 메모리 관리가 된다.
	UPROPERTY(VisibleAnywhere)
	class UMyAnimInstance* AnimInstance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn", meta = (AllowPrivateAccess = true))
		int32 AttackIndex = 0;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Weapon;

	UPROPERTY(VisibleAnywhere)
	class UMyStatComponent* StatComp;

	UPROPERTY(VisibleAnywhere)
	class UWidgetComponent* HpBar;

public:
	UPROPERTY(VisibleAnywhere, Category = "Pawn")
		float UpDownValue = 0.f;

	UPROPERTY(VisibleAnywhere, Category = "Pawn")
		float LeftRightValue = 0.f;
};
