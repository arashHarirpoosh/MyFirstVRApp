// Fill out your copyright notice in the Description page of Project Settings.


#include "MyNeptune.h"

// Sets default values for this component's properties
UMyNeptune::UMyNeptune()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//rmc = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("OrbitingMovement"));
	// ...
}


// Called when the game starts
void UMyNeptune::BeginPlay()
{
	Super::BeginPlay();
	//rmc->PivotTranslation = (Sun->GetActorLocation() - GetOwner()->GetActorLocation()) / GetOwner()->GetActorScale();
	// ...
	
}


// Called every frame
void UMyNeptune::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//rmc->RotationRate = FRotator(0, 1, 0);
	// ...
	// Every 16 seconds is one day
	GetOwner()->AddActorWorldRotation(FRotator(22.5, 22.5, 22.5) * GetWorld()->GetDeltaSeconds());

}

