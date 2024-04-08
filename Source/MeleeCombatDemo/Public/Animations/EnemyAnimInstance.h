// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EnemyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MELEECOMBATDEMO_API UEnemyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	APawn* ActorRef;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float VerticalSpeed{ 0.f };

	virtual void NativeInitializeAnimation() override;

	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
};
