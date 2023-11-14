// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbstractionPlayerCharacter.generated.h"

class UHealthComponent;
class UParticleSystemComponent;
class UDamageHandlerComponent;


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractionStart);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractionCancel);

UCLASS()
class ABSTRACTIONNEWNEW_API AAbstractionPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

	friend class UDamageHandlerComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void OnDeath(bool IsFellOut);

	UPROPERTY(EditAnywhere)
	UHealthComponent* HealthComponent;

	UFUNCTION()
		void OnDeathTimerFinished();

	UPROPERTY(EditAnywhere)
	UParticleSystemComponent* ParticleSystemComponent;

	UPROPERTY(EditAnywhere)
	UDamageHandlerComponent* DamageHandlerComponent;


	void StartInteraction();
	void StopInteraction();

	UPROPERTY(EditAnywhere)
	float TimeRestartLevelAfterDeath = 2.0f;

	FTimerHandle RestartLevelTimerHandle;

public:	

	AAbstractionPlayerCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void FellOutOfWorld(const class UDamageType& dmgType) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintCallable, Category = "Abstraction")
	void SetOnFire(float BaseDamage, float DamageTotalTime, float TakeDamageInterval);

	UFUNCTION(BlueprintCallable)
		const bool IsAlive() const;

	UFUNCTION(BlueprintCallable)
		const float GetCurrentHealth() const;




	FOnInteractionStart OnInteractionStart;
	FOnInteractionCancel OnInteractionCancel;

};
