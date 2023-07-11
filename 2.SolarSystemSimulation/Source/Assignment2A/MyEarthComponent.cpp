// Fill out your copyright notice in the Description page of Project Settings.
//Cite: https://moon.nasa.gov/inside-and-out/top-moon-questions/#:~:text=The%20Moon%20takes%20about%20one,are%20moving%20around%20the%20Sun.

#include "MyEarthComponent.h"

// Sets default values for this component's properties
UMyEarthComponent::UMyEarthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//rmc = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("OrbitingMovement"));
	//TArray<UStaticMeshComponent*> Components;
	//GetOwner()->GetComponents<UStaticMeshComponent>(Components);
	//TArray<USceneComponent*> Components;
	//GetOwner()->GetComponents<USceneComponent>(Components);
	/*for (int32 i = 0; i < Components.Num(); i++)
	{
		USceneComponent* SceneComponent = Components[i];
		SpringArmComp->SetupAttachment(SceneComponent);
	}*/
	// ...
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	
}


// Called when the game starts
void UMyEarthComponent::BeginPlay()
{
	Super::BeginPlay();
	//rmc->PivotTranslation = (Sun->GetActorLocation() - GetOwner()->GetActorLocation()) / GetOwner()->GetActorScale();
	SpringArmComp->SetWorldLocation(GetOwner()->GetActorLocation());
	SpringArmComp->TargetArmLength = 0;
	SpringArmComp->SetupAttachment(GetOwner()->GetRootComponent());
	Moon->AttachToComponent(SpringArmComp, FAttachmentTransformRules::KeepWorldTransform);

	// ...
	
}


// Called every frame
void UMyEarthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//rmc_orbit_around_planet->bRotationInLocalSpace = false;

	//rmc->RotationRate = FRotator(0, 15, 0);
	//rmc->PivotTranslation = FVector(0, 0, 0);
	//rmc->RotationRate = FRotator(0, 0, 0);
	SpringArmComp->SetWorldLocation(GetOwner()->GetActorLocation());
	// Rotating the Moon
	SpringArmComp->AddWorldRotation(FRotator(0, 0.26 / Moon->GetActorScale().Z, 0));

	// Every 24 seconds is one day
	GetOwner()->AddActorWorldRotation(FRotator(15, 15, 15) * GetWorld()->GetDeltaSeconds());

	//rmc->PivotTranslation = FVector(0, 0, 0);
	//rmc->bRotationInLocalSpace = false;
	//rmc->RotationRate = FRotator(0, 15, 0);
	//rmc->PivotTranslation = FVector(0, 0, 0);
	//rmc->RotationRate = FRotator(0, 0, 0);

	//GetOwner()->AddActorLocalRotation(FRotator(0.1, 0.01, 0.01));
	
	//GetOwner()->SetActorLocation(GetOwner()->GetActorLocation() * 0.1 );

	//GetOwner()->AddActorWorldTransformKeepScale(FTransform(FVector(150.0, 0.0, 0.0)));
	
	//GetOwner()->AddActorLocalTransform(FTransform(FRotator(0.0, 10.0, 0.0)));

	// ...
}

