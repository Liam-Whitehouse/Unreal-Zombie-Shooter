// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/AIZombieController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"

AAIZombieController::AAIZombieController()
{
	Blackboard = CreateDefaultSubobject<UBlackboardComponent>("BlackboardComp");
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>("BehaviorTreeComp");
}