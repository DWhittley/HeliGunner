// Fill out your copyright notice in the Description page of Project Settings.


#include "W_PlayerScore.h"

void UW_PlayerScore::NativeConstruct()
{
	SetScore(0);
	SetAmmo(100);
}

void UW_PlayerScore::SetScore(int score)
{
	if (!ScoreText) return;
	
	ScoreText->SetText(FText::FromString(FString::FromInt(score)));
}

void UW_PlayerScore::SetAmmo(int ammo)
{
	if (!AmmoText) return;
	
	AmmoText->SetText(FText::FromString(FString::FromInt(ammo)));
}
