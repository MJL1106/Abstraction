// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectiveWorldSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "../AbstractionNewNEwGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "ObjectiveHud.h"
#include "MyCameraActor.h"

void UObjectiveWorldSubsystem::Deinitialize()
{
	ObjectiveWidget = nullptr;
	ObjectivesCompleteWidget = nullptr;
}


void UObjectiveWorldSubsystem::CreateObjectiveWidgets()
{
	// Check if the widgets have already been created
	if (ObjectiveWidget == nullptr || ObjectivesCompleteWidget == nullptr)
	{
		AAbstractionNewNEwGameModeBase* GameMode = Cast<AAbstractionNewNEwGameModeBase>(GetWorld()->GetAuthGameMode());
		if (GameMode)
		{
			APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
			if (PlayerController)
			{
				// Attempt to create the Objective HUD widget
				ObjectiveWidget = CreateWidget<UObjectiveHud>(PlayerController, GameMode->ObjectiveWidgetClass);
				// Attempt to create the Objectives Complete widget
				ObjectivesCompleteWidget = CreateWidget<UUserWidget>(PlayerController, GameMode->ObjectivesCompleteWidgetClass);
			}
	
		}

	}


}

void UObjectiveWorldSubsystem::DisplayObjectiveWidget()
{
	if (ObjectiveWidget)
	{
		if (!ObjectiveWidget->IsInViewport()) {
			ObjectiveWidget->AddToViewport();
		}
		ObjectiveWidget->UpdateObjectiveText(GetCompletedObjectiveCount(), Objectives.Num());
	}
}

void UObjectiveWorldSubsystem::RemoveObjectiveWidget()
{
	if (ObjectiveWidget)
	{
		ObjectiveWidget->RemoveFromViewport();
	}
}

void UObjectiveWorldSubsystem::DisplayObjectivesCompleteWidget()
{
	if (ObjectivesCompleteWidget)
	{
		ObjectivesCompleteWidget->AddToViewport();
	}
}

void UObjectiveWorldSubsystem::RemoveObjectivesCompleteWidget()
{
	if (ObjectivesCompleteWidget)
	{
		ObjectivesCompleteWidget->RemoveFromViewport();
	}
}

FString UObjectiveWorldSubsystem::GetCurrentObjectiveDescription()
{
	if (!Objectives.IsValidIndex(0) || Objectives[0]->GetState() == EObjectiveState::OS_Inactive)
	{
		return TEXT("N/A");
	}

	FString RetObjective = Objectives[0]->GetDescription();
	if (Objectives[0]->GetState() == EObjectiveState::OS_Completed)
	{
		RetObjective += TEXT(" Completed!");
	}
	return RetObjective;
}

void UObjectiveWorldSubsystem::AddObjective(UObjectiveComponent* ObjectiveComponent)
{
	check(ObjectiveComponent);

	size_t PrevSize = Objectives.Num();
	Objectives.AddUnique(ObjectiveComponent);
	if (Objectives.Num() > PrevSize)
	{
		ObjectiveComponent->OnStateChanged().AddUObject(this, &UObjectiveWorldSubsystem::OnObjectiveStateChanged);
	}
}



void UObjectiveWorldSubsystem::RemoveObjective(UObjectiveComponent* ObjectiveComponent)
{
	int32 numRemoved = ObjectiveComponent->OnStateChanged().RemoveAll(this);
	check(numRemoved);
	Objectives.Remove(ObjectiveComponent);
}

uint32 UObjectiveWorldSubsystem::GetCompletedObjectiveCount()
{
	uint32 ObjectivedCompleted = 0u;
	for (const UObjectiveComponent* OC : Objectives)
	{
		if (OC && OC->GetState() == EObjectiveState::OS_Completed)
		{
			++ObjectivedCompleted;
		}
	}

	return ObjectivedCompleted;
}

void UObjectiveWorldSubsystem::OnMapStart()
{
	AAbstractionNewNEwGameModeBase* GameMode = Cast<AAbstractionNewNEwGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		CreateObjectiveWidgets();
		DisplayObjectiveWidget();
	}
}

void UObjectiveWorldSubsystem::AddCamera(AMyCameraActor* CameraComponent) {

	Cameras.Add(CameraComponent);
}


void UObjectiveWorldSubsystem::OnObjectiveStateChanged(UObjectiveComponent* ObjectiveComponent, EObjectiveState ObjectiveState)
{
	if (Objectives.Num() == 0 || !Objectives.Contains(ObjectiveComponent))
	{
		return;
	}

	if (ObjectiveWidget && ObjectivesCompleteWidget)
	{
		if ((ObjectiveState == EObjectiveState::OS_Completed) && GetCompletedObjectiveCount() == Objectives.Num())
		{
			DisplayObjectivesCompleteWidget();
		}

			DisplayObjectiveWidget();
	}
}
