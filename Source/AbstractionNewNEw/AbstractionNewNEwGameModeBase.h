// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "AbstractionNewNEwGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ABSTRACTIONNEWNEW_API AAbstractionNewNEwGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	void StartPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> ObjectiveWidgetClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> ObjectivesCompleteWidgetClass;

};
