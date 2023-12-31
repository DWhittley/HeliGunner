// Fill out your copyright notice in the Description page of Project Settings.

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnemyAIController.h"

AEnemyAIController::AEnemyAIController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior Tree Component"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard Component"));
	PawnSensing = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensing"));
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(BehaviorTree.Get()))
	{
		RunBehaviorTree(BehaviorTree.Get());
		BehaviorTreeComponent->StartTree(*BehaviorTree.Get());
	}
	PawnSensing->OnSeePawn.AddDynamic(this, &AEnemyAIController::OnSeePawn);
}

void AEnemyAIController::OnSeePawn(APawn* PlayerPawn)
{
	ABP_Player* player = Cast<ABP_Player>(PlayerPawn);

	if (player)
	{
		SetCanSeePlayer(true, player);
		RunTriggerableTimer();
		UE_LOG(LogTemp, Warning, TEXT("Stop Attacking"));
	}
}

void AEnemyAIController::SetCanSeePlayer(bool SeePlayer, class UObject* Player)
{
	UBlackboardComponent* bb = GetBlackboardComponent();
	if (SeePlayer)
	{
		bb->SetValueAsBool(FName("Can See Player"), SeePlayer);
		bb->SetValueAsObject(FName("Player Target"), Player);
	}
	else
	{
		bb->SetValueAsBool(FName("Can See Player"), SeePlayer);
	}
}

void AEnemyAIController::RunTriggerableTimer()
{
	GetWorld()->GetTimerManager().ClearTimer(RetriggerableTimerHandle);

	FunctionDelegate.BindUFunction(this, FName("SetCanSeePlayer"), false, GetPawn());

	GetWorld()->GetTimerManager().SetTimer(RetriggerableTimerHandle, FunctionDelegate, PawnSensing->SensingInterval * 2.0f, false);
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (IsValid(Blackboard.Get()) && IsValid(BehaviorTree.Get())) 
	{
		Blackboard-> InitializeBlackboard(*BehaviorTree.Get()->BlackboardAsset.Get());
	}
}
