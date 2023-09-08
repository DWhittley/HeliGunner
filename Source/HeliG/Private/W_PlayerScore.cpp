// Fill out your copyright notice in the Description page of Project Settings.


#include "W_PlayerScore.h"

void UW_PlayerScore::SetScore(int value)
{
	if (ScoreText)
	{
		ScoreText->SetText(FText::FromString(FString::FromInt(value)));
	}
}

void UW_PlayerScore::SetAmmo(int value)
{
	if (AmmoText)
	{
		AmmoText->SetText(FText::FromString(FString::FromInt(value)));
	}
}
