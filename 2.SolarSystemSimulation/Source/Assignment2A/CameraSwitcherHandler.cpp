// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraSwitcherHandler.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACameraSwitcherHandler::ACameraSwitcherHandler()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraSwitcherHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraSwitcherHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACameraSwitcherHandler::SwitchCamera(const FInputActionInstance& Instance)
{
	const float SmoothBlendTime = 0.75f;
	bool BoolValue = Instance.GetValue().Get<bool>();
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Messagegoes here"));
    //Find the actor that handles control for the local player.
	if (BoolValue) {
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			if (CameraTwo && (OurPlayerController->GetViewTarget() == CameraOne))
			{
				//Blend smoothly to camera two.
				OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
			}
			else if (CameraOne && (OurPlayerController->GetViewTarget() == CameraFour))
			{
				//Blend smoothly to camera one.
				OurPlayerController->SetViewTargetWithBlend(CameraOne, SmoothBlendTime);
			}
			else if (CameraThree && (OurPlayerController->GetViewTarget() == CameraTwo))
			{
				//Blend smoothly to camera three.
				OurPlayerController->SetViewTargetWithBlend(CameraThree);
			}
			else if (CameraFour)
			{
				//Blend smoothly to camera four.
				OurPlayerController->SetViewTargetWithBlend(CameraFour);
			}
		}
	}

}

// Called to bind functionality to input
void ACameraSwitcherHandler::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (ULocalPlayer* LocalPlayer = Cast<APlayerController>(Controller)->GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (!IMC_Normal_Controls.IsNull())
			{
				InputSystem->AddMappingContext(IMC_Normal_Controls.LoadSynchronous(), 0);
			}
		}
	}

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	Input->BindAction(IA_SC, ETriggerEvent::Started, this, &ACameraSwitcherHandler::SwitchCamera);

}

