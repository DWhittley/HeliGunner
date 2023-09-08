// Copyright Epic Games, Inc. All Rights Reserved.


#include "HeliGGameModeBase.h"


void AHeliGGameModeBase::StartPlay()
{
	Super::StartPlay();

	// C asset() <- stop the code here
	check(GEngine != nullptr)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World! This is FPSGameModeBase!"));

	UE_LOG(LogTemp, Warning, TEXT("Hello World! This is FPSGameModeBase!"));

	UE_LOG(LogTemp, Warning, TEXT("Hello World! This is FPSGameModeBase!"));
}