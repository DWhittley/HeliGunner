// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "W_PlayerScore.h"
#include "HeliGGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class HELIG_API AHeliGGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	UW_PlayerScore* CurrentWidget;

protected:
	virtual void StartPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class UW_PlayerScore> StartingWidgetClass;
};
