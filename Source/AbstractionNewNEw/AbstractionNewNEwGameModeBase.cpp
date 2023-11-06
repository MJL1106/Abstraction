// Copyright Epic Games, Inc. All Rights Reserved.


#include "AbstractionNewNEwGameModeBase.h"
#include "ObjectiveWorldSubsystem.h"

void AAbstractionNewNEwGameModeBase::StartPlay()
{
	Super::StartPlay();
    if (UObjectiveWorldSubsystem* ObjectiveSubsystem = GetWorld()->GetSubsystem<UObjectiveWorldSubsystem>())
    {
        ObjectiveSubsystem->OnMapStart();
    }
}

