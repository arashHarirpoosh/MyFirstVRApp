// Fill out your copyright notice in the Description page of Project Settings.
// Cite: https://sos.noaa.gov/catalog/datasets/planet-rotations/
// Cite: https://forums.unrealengine.com/t/how-to-handle-child-components/677396/4
// Cite: https://docs.unrealengine.com/4.27/en-US/InteractiveExperiences/UsingCameras/SpringArmComponents/
// Cite: https://public.nrao.edu/ask/which-planet-orbits-our-sun-the-fastest/#:~:text=Mercury%3A%2047.87%20km%2Fs%20(,period%20of%20about%20686.93%20days

#include "MySunComponent.h"

// Sets default values for this component's properties
UMySunComponent::UMySunComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//rmc = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));
	//rmc->RotationRate = FRotator(0, 0, 0);
	//planetEarth = CreateDefaultSubobject<AActor>("PlanetEarth");
	//CreateDefaultSubobject< URotatingMovementComponent>("Root");
	//planetEarth->set
	//planetEarth->AttachToActor(GetOwner(), FAttachmentTransformRules(EAttachmentRule::KeepWorld, true));
	//URotatingMovementComponent().RotationRate = FRotator(0.f, 90.f, 0.f);
	// ...

	SpringArmCompMercury = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmCompMercury"));
	SpringArmCompVenus = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmCompVenus"));
	SpringArmCompEarth = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmCompEarth"));
	SpringArmCompMars = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmCompMars"));
	SpringArmCompJupiter = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmCompJupiter"));
	SpringArmCompSaturn = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmCompSaturn"));
	SpringArmCompUranus = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmCompUranus"));
	SpringArmCompNeptune = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmCompNeptune"));

	SpringArmCompMercury->TargetArmLength = 0;
	SpringArmCompVenus->TargetArmLength = 0;
	SpringArmCompEarth->TargetArmLength = 0;
	SpringArmCompMars->TargetArmLength = 0;
	SpringArmCompJupiter->TargetArmLength = 0;
	SpringArmCompSaturn->TargetArmLength = 0;
	SpringArmCompUranus->TargetArmLength = 0;
	SpringArmCompNeptune->TargetArmLength = 0;

	//SpringArmCompEarth->SetWorldLocation(GetOwner()->GetActorLocation());

}


// Called when the game starts
void UMySunComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	SpringArmCompMercury->SetupAttachment(GetOwner()->GetRootComponent());
	SpringArmCompVenus->SetupAttachment(GetOwner()->GetRootComponent());
	SpringArmCompEarth->SetupAttachment(GetOwner()->GetRootComponent());
	SpringArmCompMars->SetupAttachment(GetOwner()->GetRootComponent());
	SpringArmCompJupiter->SetupAttachment(GetOwner()->GetRootComponent());
	SpringArmCompSaturn->SetupAttachment(GetOwner()->GetRootComponent());
	SpringArmCompUranus->SetupAttachment(GetOwner()->GetRootComponent());
	SpringArmCompNeptune->SetupAttachment(GetOwner()->GetRootComponent());

	Mercury->AttachToComponent(SpringArmCompMercury, FAttachmentTransformRules::KeepWorldTransform);
	Venus->AttachToComponent(SpringArmCompVenus, FAttachmentTransformRules::KeepWorldTransform);
	Earth->AttachToComponent(SpringArmCompEarth, FAttachmentTransformRules::KeepWorldTransform);
	Mars->AttachToComponent(SpringArmCompMars, FAttachmentTransformRules::KeepWorldTransform);
	Jupiter->AttachToComponent(SpringArmCompJupiter, FAttachmentTransformRules::KeepWorldTransform);
	Saturn->AttachToComponent(SpringArmCompSaturn, FAttachmentTransformRules::KeepWorldTransform);
	Uranus->AttachToComponent(SpringArmCompUranus, FAttachmentTransformRules::KeepWorldTransform);
	Neptune->AttachToComponent(SpringArmCompNeptune, FAttachmentTransformRules::KeepWorldTransform);


	
}


// Called every frame
void UMySunComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//AddLocalRotation(FRotator(0.0, rotate_x, 0.0), false, 0, ETeleportType::None);
	//GetOwner()->AddActorWorldRotation(, false, 0, ETeleportType::None);

	SpringArmCompMercury->SetWorldLocation(GetOwner()->GetActorLocation());
	SpringArmCompVenus->SetWorldLocation(GetOwner()->GetActorLocation());
	SpringArmCompEarth->SetWorldLocation(GetOwner()->GetActorLocation());
	SpringArmCompMars->SetWorldLocation(GetOwner()->GetActorLocation());
	SpringArmCompJupiter->SetWorldLocation(GetOwner()->GetActorLocation());
	SpringArmCompSaturn->SetWorldLocation(GetOwner()->GetActorLocation());
	SpringArmCompUranus->SetWorldLocation(GetOwner()->GetActorLocation());
	SpringArmCompNeptune->SetWorldLocation(GetOwner()->GetActorLocation());
	
	// Slowest Orbitting Speed Will be 0.09

	SpringArmCompMercury->AddWorldRotation(FRotator(0, 0.79 / Mercury->GetActorScale().Z, 0));
	SpringArmCompVenus->AddWorldRotation(FRotator(0, 0.58 / Venus->GetActorScale().Z, 0));
	SpringArmCompEarth->AddWorldRotation(FRotator(0, 0.49 / Earth->GetActorScale().Z, 0));
	SpringArmCompMars->AddWorldRotation(FRotator(0, 0.4 / Mars->GetActorScale().Z, 0));
	SpringArmCompJupiter->AddWorldRotation(FRotator(0, 0.21 / Jupiter->GetActorScale().Z, 0));
	SpringArmCompSaturn->AddWorldRotation(FRotator(0, 0.16 / Saturn->GetActorScale().Z, 0));
	SpringArmCompUranus->AddWorldRotation(FRotator(0, 0.11 / Uranus->GetActorScale().Z, 0));
	SpringArmCompNeptune->AddWorldRotation(FRotator(0, 0.09 / Neptune->GetActorScale().Z, 0));


	GetOwner()->AddActorWorldRotation(FRotator(0.55, 0.55, 0.55) * GetWorld()->GetDeltaSeconds());

	//rmc->RotationRate = FRotator(0.0, 1.0, 0.0);
	//SetUsingAbsoluteRotation(true);
	//GetOwner()->AddActorWorldRotation(FRotator(0.0, 1.0, 0.0));
	//AddLocalRotation(FRotator(10.0, 0.5, 0.5));
	//GetOwner();
	//AddLocalRotation(FRotator(1.0, 1.0, 0.0));

	// ...
}

