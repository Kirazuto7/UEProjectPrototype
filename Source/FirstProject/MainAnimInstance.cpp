// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

void UMainAnimInstance::NativeInitializeAnimation()
{
	if (Pawn == nullptr) 
		Pawn = TryGetPawnOwner();

	
}

void UMainAnimInstance::UpdateAnimationProperties()
{
	if (Pawn == nullptr)
		Pawn = TryGetPawnOwner();

	if (Pawn)
	{
		FVector Speed = Pawn->GetVelocity();
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.f);
		movementSpeed = LateralSpeed.Size(); //gives the magnitude of the fvector

		bIsInAir = Pawn->GetMovementComponent()->IsFalling();
	}
}