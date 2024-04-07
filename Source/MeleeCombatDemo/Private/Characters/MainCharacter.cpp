// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/MainCharacter.h"
#include "Combat/LockonComponent.h"
#include "Animations/PlayerAnimInstance.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	LockonComp = FindComponentByClass<ULockonComponent>();
	PlayerAnim = Cast<UPlayerAnimInstance>(GetMesh()->GetAnimInstance());

	if (PlayerAnim)
	{
		UE_LOG(LogClass, Warning, TEXT("Subscribed to anim instance"));
		/*FScriptDelegate ScriptDelegate;
		ScriptDelegate.BindUFunction(PlayerAnim, "HandleUpdatedTarget"); */
		LockonComp->OnUpdatedTargetDelegate.AddDynamic(
			PlayerAnim, &UPlayerAnimInstance::HandleUpdatedTarget
		);
	}
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

