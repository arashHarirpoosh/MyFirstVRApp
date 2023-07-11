// Fill out your copyright notice in the Description page of Project Settings.


#include "MyVenusComponent.h"

// Sets default values for this component's properties
UMyVenusComponent::UMyVenusComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//rmc = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));
	//rmc->bRotationInLocalSpace = true;
	// ...
}


// Called when the game starts
void UMyVenusComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyVenusComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//rmc->RotationRate = FRotator(0, 20, 0);
	// ...
	// 
	// Every (243 * 24) + 0.43 seconds is one day
	GetOwner()->AddActorWorldRotation(FRotator(0.061, 0.061, 0.061) * GetWorld()->GetDeltaSeconds());

}

