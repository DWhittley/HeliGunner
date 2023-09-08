// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "W_PlayerScore.generated.h"

/**
 * 
 */
UCLASS()
class HELIG_API UW_PlayerScore : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ScoreText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* AmmoText;

	int Score;
	void SetScore(int value);

	int Ammo;
	void SetAmmo(int value);
};
