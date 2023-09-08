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
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ScoreText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* AmmoText;

	UFUNCTION()
	
	void SetScore(int value);

	UFUNCTION()
	
	void SetAmmo(int value);

private:
	int Score;
	int Ammo;
};
