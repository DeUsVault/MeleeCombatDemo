// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/AttackTracing.h"
#include "MainCharacter.generated.h"

UCLASS()
class MELEECOMBATDEMO_API AMainCharacter : public ACharacter, public IAttackTracing
{
	GENERATED_BODY()

	class ULockonComponent* LockonComp;
	class UPlayerAnimInstance* PlayerAnim; 
	class UAttackComponent* AttackComp;
	class UTraceComponent* TraceComp;

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void ToggleTrace(bool bIsTracing) override;
};
