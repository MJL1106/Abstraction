// Copyright Epic Games, Inc. All Rights Reserved.


#include "AbstractionNewNEwGameModeBase.h"
#include "ObjectiveWorldSubsystem.h"

void AAbstractionNewNEwGameModeBase::StartPlay()
{
	Super::StartPlay();

	UObjectiveWorldSubsystem* ObjectiveWorldSubsystem = GetWorld()->GetSubsystem<UObjectiveWorldSubsystem>();
	if (ObjectiveWorldSubsystem)
	{
		ObjectiveWorldSubsystem->CreateObjectiveWidget(ObjectiveWidgetClass);
		ObjectiveWorldSubsystem->DisplayObjectiveWidget();
	}
}

