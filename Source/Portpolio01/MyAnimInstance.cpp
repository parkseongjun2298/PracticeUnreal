// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include"GameFramework/Character.h"
#include"GameFramework/PawnMovementComponent.h"
UMyAnimInstance::UMyAnimInstance()
{
	const ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("AnimMontage'/Game/Animations/Kwang_Skeleton_Montage.Kwang_Skeleton_Montage'"));
	if (AM.Succeeded())
	{
		AttackMontage = AM.Object;
	}
}
void UMyAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		Speed = Pawn->GetVelocity().Size();

		auto character = Cast<ACharacter>(Pawn);
		if (character)
		{
			isFalling = character->GetMovementComponent()->IsFalling();
		}
	}
}

void UMyAnimInstance::PlayAttackMontage()
{
		Montage_Play(AttackMontage,1.f);

}
