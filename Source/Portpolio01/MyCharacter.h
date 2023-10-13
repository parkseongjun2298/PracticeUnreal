// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class PORTPOLIO01_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void UpDown(float Value);
	void RightLeft(float Value);
	void Yaw(float Value);
	void Attack();
private:
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere,Category=Pawn)
		bool isAttacking;
	UPROPERTY();
	class UMyAnimInstance* AnimInstance;

	UPROPERTY(VisibleAnywhere, Category = Pawn)
		bool isMontageCheck = false;

	UFUNCTION()
		void OnAttackMyMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	UPROPERTY()
		int32 AttackCount=0;
public:

	UPROPERTY()
		float UpDownValue = 0;
	UPROPERTY()
		float LeftRightValue = 0;
};
