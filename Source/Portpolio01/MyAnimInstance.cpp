// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include"GameFramework/Character.h"
#include"GameFramework/PawnMovementComponent.h"
#include"MyCharacter.h"
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

		auto character = Cast<AMyCharacter>(Pawn);
		if (character)
		{
			isFalling = character->GetMovementComponent()->IsFalling();

			Vertical = character->UpDownValue;
			Horizontal = character->LeftRightValue;
		}
	}
}

void UMyAnimInstance::PlayAttackMontage()
{
		Montage_Play(AttackMontage,1.f);

}

FName UMyAnimInstance::GetAttackMontageName(int32 SectionIndex)
{
	//여기 이름이 언리얼 몽타주 섹션이름이랑 같아야함
	return FName(*FString::Printf(TEXT("Attack%d"),SectionIndex));

}

void UMyAnimInstance::AnimNotify_AttackHit()
{
	UE_LOG(LogTemp, Log, TEXT("AnimNotify_AttackHit"));
}


void UMyAnimInstance::JumpToSection(int32 SectionIndex)
{
	FName Name = GetAttackMontageName(SectionIndex);
	Montage_JumpToSection(Name, AttackMontage);
}