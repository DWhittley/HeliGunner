// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBTTask_FindRandomLocation.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UEnemyBTTask_FindRandomLocation::UEnemyBTTask_FindRandomLocation()
{
	NodeName = TEXT("Find Random Location");

	// accept only vectors for the blackboard key so add filter
	BlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UEnemyBTTask_FindRandomLocation, BlackboardKey));
}

EBTNodeResult::Type UEnemyBTTask_FindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	FNavLocation Location{};

	// Get AI Pawn
	AAIController* AIController = OwnerComp.GetAIOwner();
	const APawn* AIPawn = AIController->GetPawn();

	// Get Pawn origin
	const FVector Origin = AIPawn->GetActorLocation();

	// Obtain Navigation System and find random location
	const UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());
	if (IsValid(NavSystem) && NavSystem->GetRandomPointInNavigableRadius(Origin, SearchRadius, Location))
	{
		AIController->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.SelectedKeyName,
			Location.Location);  // set the location vector as the location to go to
	}

	// Signal the BehaviorTreeComponent that the task finished with success
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}

FString UEnemyBTTask_FindRandomLocation::GetStaticDescription() const
{
	return FString::Printf(TEXT("Vector: %s"), *BlackboardKey.SelectedKeyName.ToString());
}
