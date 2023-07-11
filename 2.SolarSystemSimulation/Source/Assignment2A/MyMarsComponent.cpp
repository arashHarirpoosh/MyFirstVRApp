// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMarsComponent.h"

// Sets default values for this component's properties
UMyMarsComponent::UMyMarsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//rmc = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("OrbitingMovement"));
	// ...
}


// Called when the game starts
void UMyMarsComponent::BeginPlay()
{
	Super::BeginPlay();
	//rmc->PivotTranslation = (Sun->GetActorLocation() - GetOwner()->GetActorLocation()) / GetOwner()->GetActorScale();
	// ...
	
}


// Called every frame
void UMyMarsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//rmc->RotationRate = FRotator(0, 1, 0);
	/*GetOwner()->AddActorWorldTransformKeepScale(FTransform(FVector(0, 0, 0)));
	GetOwner()->AddActorWorldTransformKeepScale(FTransform(FRotator(15, 15, 15)));*/

	// ...
	// Every 24.6 seconds is one day
	GetOwner()->AddActorWorldRotation(FRotator(14.63, 14.63, 14.63) * GetWorld()->GetDeltaSeconds());

}

