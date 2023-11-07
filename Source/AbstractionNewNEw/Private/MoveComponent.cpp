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

        //Determines the new location for this frame
        FVector NewLocation = CurrentLocation + Direction * DeltaMove;


        bool bReverse = false;

        //Checks if the movement distance has been exceeded on the X
        if (FMath::Abs((NewLocation - OriginalLocation).X) > MoveDistanceX)
        {
            //Sets NewLocation to maximum allowed distance of the X
            NewLocation.X = OriginalLocation.X + MoveDistanceX * FMath::Sign(Direction.X);
            bReverse = true;
        }
        
        //Checks if the movement distance has been exceeded on the Y
        if (FMath::Abs((NewLocation - OriginalLocation).Z) > MoveDistanceZ)
        {
            //Sets NewLocation to maximum allowed distance of the Y
            NewLocation.Z = OriginalLocation.Z + MoveDistanceZ * FMath::Sign(Direction.Z);
            bReverse = true;
        }

        Owner->SetActorLocation(NewLocation);

        //Reverses the direction by mutiplying the vector by -1
        if (bReverse)
        {
            MoveDirection *= -1;
        }
    }
}

