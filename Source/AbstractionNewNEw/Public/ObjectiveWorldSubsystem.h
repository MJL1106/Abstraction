// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Subsystems/WorldSubsystem.h"
#include "ObjectiveComponent.h"
#include "ObjectiveWorldSubsystem.generated.h"

class AMyCameraActor;
class UObjectiveHud;
class UUserWidget;

UCLASS()
class ABSTRACTIONNEWNEW_API UObjectiveWorldSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
		FString GetCurrentObjectiveDescription();

	UFUNCTION(BlueprintCallable)
		void AddObjective(UObjectiveComponent* ObjectiveComponent);

	UFUNCTION(BlueprintCallable)
		void RemoveObjective(UObjectiveComponent* ObjectiveComponent);

	UFUNCTION(BlueprintCallable)
		void AddCamera(AMyCameraActor* CameraComponent);

	UFUNCTION(BlueprintCallable)
		void OnMapStart();


protected:
	virtual void Deinitialize() override;

	void CreateObjectiveWidgets();

	void DisplayObjectiveWidget();
	void RemoveObjectiveWidget();

	void DisplayObjectivesCompleteWidget();
	void RemoveObjectivesCompleteWidget();

	uint32 GetCompletedObjectiveCount();

	void OnObjectiveStateChanged(UObjectiveComponent* ObjectiveComponent, EObjectiveState ObjectiveState);

private:
	UObjectiveHud* ObjectiveWidget = nullptr;
	UUserWidget* ObjectivesCompleteWidget = nullptr;

	//add remove them
	//sign up for callback onchanged

	TArray<UObjectiveComponent*> Objectives;


	TArray<AMyCameraActor*> Cameras;
	
};
