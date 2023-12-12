// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableDoor.h"
#include "DoorInteractionComponent.h"
#include "Components/CapsuleComponent.h"

AInteractableDoor::AInteractableDoor() : Super()
{
	DoorInteractionComponent = CreateDefaultSubobject<UDoorInteractionComponent>(TEXT("DoorInteractionComponent"));
	if (DoorInteractionComponent->GetTriggerCapsule())
	{
		DoorInteractionComponent->GetTriggerCapsule()->SetupAttachment(RootComponent);
	}
	DoorOpenSound = CreateDefaultSubobject<UAudioComponent>(TEXT("DoorOpenSound"));
	DoorOpenSound->SetupAttachment(RootComponent);
}

void AInteractableDoor::BeginPlay()
{
	Super::BeginPlay();
	DoorInteractionComponent->InteractionSuccess.AddDynamic(this, &AInteractableDoor::OnInteractionSuccess);
}

void AInteractableDoor::OpenDoor()
{

	DoorInteractionComponent->OpenDoor();
}

void AInteractableDoor::OnInteractionSuccess()
{
	if (DoorOpenSound)
	{
		DoorOpenSound->Play();
	}
	OnDoorOpen.Broadcast();    

}

