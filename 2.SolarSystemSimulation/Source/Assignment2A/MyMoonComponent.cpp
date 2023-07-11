// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMoonComponent.h"

// Sets default values for this component's properties
UMyMoonComponent::UMyMoonComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//rmc = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));
	//rmc->bRotationInLocalSpace = true;
	//rmc->RotationRate = FRotator(100.0, 100.0, 100.1);
	//GetOwner()->AttachToActor(Earth, FAttachmentTransformRules(EAttachmentRule::KeepWorld, false));
	// ...
}


// Called when the game starts
void UMyMoonComponent::BeginPlay()
{
	Super::BeginPlay();
	//rmc->PivotTranslation = (Earth->GetActorLocation() - GetOwner()->GetActorLocation()) / GetOwner()->GetActorScale();

	// ...
	
}


// Called every frame
void UMyMoonComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//rmc->PivotTranslation = (1.0) / GetOwner()->GetActorScale();
	//rmc->PivotTranslation = FVector(-400, 0, 0);
	//rmc->PivotTranslation = (Earth->GetActorLocation() - MoonDistance) / GetOwner()->GetActorScale();

	//rmc->PivotTranslation = (Earth->GetActorLocation() - GetOwner()->GetActorLocation()) / GetOwner()->GetActorScale();
	//rmc->RotationRate = FRotator(0, 27, 27);
	//rmc->RotationRate = FRotator(0, 0, 0);
	//GetOwner()->AddActorLocalTransform(Earth->GetActorTransform());

	// ...
	GetOwner()->AddActorWorldRotation(FRotator(0.55, 0.55, 0.55) * GetWorld()->GetDeltaSeconds());
	//GetOwner()->AddActorLocalRotation(FRotator(100, 100, 100) * GetWorld()->GetDeltaSeconds());

}

