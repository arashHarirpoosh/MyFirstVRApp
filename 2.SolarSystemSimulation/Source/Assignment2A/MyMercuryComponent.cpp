// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMercuryComponent.h"

// Sets default values for this component's properties
UMyMercuryComponent::UMyMercuryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//rmc = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));
	//rmc->bRotationInLocalSpace = false;
	// ...
}


// Called when the game starts
void UMyMercuryComponent::BeginPlay()
{
	Super::BeginPlay();
	//rmc->PivotTranslation = (Sun->GetActorLocation() - GetOwner()->GetActorLocation()) / GetOwner()->GetActorScale();

	// ...

}


// Called every frame
void UMyMercuryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//rmc->RotationRate = FRotator(0, 20, 0);
	// ...
	// 
	// Every (58 * 24) + 16 seconds is one day
	GetOwner()->AddActorWorldRotation(FRotator(0.255, 0.255, 0.255) * GetWorld()->GetDeltaSeconds());

}

