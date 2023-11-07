// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveComponent.h"

// Sets default values for this component's properties
UMoveComponent::UMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


}


// Called when the game starts
void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	OriginalLocation = GetOwner()->GetActorLocation();
	
}


// Called every frame
void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


    AActor* Owner = GetOwner();
    if (Owner)
    {
        FVector CurrentLocation = Owner->GetActorLocation();
        FVector Direction = MoveDirection;
        float DeltaMove = Speed * DeltaTime;

        FVector NewLocation = CurrentLocation + Direction * DeltaMove;
        bool bReverse = false;

        if (FMath::Abs((NewLocation - OriginalLocation).X) > MoveDistanceX)
        {
            NewLocation.X = OriginalLocation.X + MoveDistanceX * FMath::Sign(Direction.X);
            bReverse = true;
        }

        if (FMath::Abs((NewLocation - OriginalLocation).Z) > MoveDistanceZ)
        {
            NewLocation.Z = OriginalLocation.Z + MoveDistanceZ * FMath::Sign(Direction.Z);
            bReverse = true;
        }

        Owner->SetActorLocation(NewLocation);

        if (bReverse)
        {
            MoveDirection *= -1;
        }
    }
}

