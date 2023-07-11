// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharacter.h"

// Sets default values
AFirstPersonCharacter::AFirstPersonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	camera->SetupAttachment(RootComponent);
	camera->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
}

// Called when the game starts or when spawned
void AFirstPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFirstPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Move the Character  into the In and Out Directions if W/S Key has been Pressed
void AFirstPersonCharacter::KB_Move_InOut(const FInputActionInstance& Instance)
{
	// Get the value of the Input Action for whatever type you want here...
	float FloatValue_IO = Instance.GetValue().Get<float>();

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Something is pressed!"));
	
	// Do your cool stuff here!
	if (FloatValue_IO != 0.f) {
		AddMovementInput(GetActorForwardVector(), FloatValue_IO);
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Cyan, TEXT("Move In or Out Direction!"));
	}
}

// Move the Character  into the Left and Right Directions if A/D Key has been Pressed
void AFirstPersonCharacter::KB_Move_LeftRight(const FInputActionInstance& Instance)
{
	// Get the value of the Input Action for whatever type you want here...
	float FloatValue_MLR = Instance.GetValue().Get<float>();
	// Do your cool stuff here!
	if (FloatValue_MLR != 0) {
		AddMovementInput(GetActorRightVector(), FloatValue_MLR);
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Emerald, TEXT("Move Left or Right Direction!"));
	}
}

// Perform the Character Rotating for Looking into the Up and Down Directions
void AFirstPersonCharacter::KB_Look_UpDown(const FInputActionInstance& Instance)
{
	// Get the value of the Input Action for whatever type you want here...
	float FloatValue_LUD = Instance.GetValue().Get<float>();

	// Do your cool stuff here!
	AddControllerPitchInput(-20 * FloatValue_LUD * GetWorld()->GetDeltaSeconds());
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, TEXT("Look Up or Down Direction!"));
}

// Perform the Character Rotating for Looking into the Left and Right Directions
void AFirstPersonCharacter::KB_Look_LeftRight(const FInputActionInstance& Instance)
{
	// Get the value of the Input Action for whatever type you want here...
	float FloatValue_LLR = Instance.GetValue().Get<float>();

	// Do your cool stuff here!
	AddControllerYawInput(20 * FloatValue_LLR * GetWorld()->GetDeltaSeconds());
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("Look Left or Right Direction!"));
}

// Print The Given Message on the Screen If Space button is Pressed
void AFirstPersonCharacter::KB_Jump(const FInputActionInstance& Instance)
{
	bool BoolValue = Instance.GetValue().Get<bool>();
	if (BoolValue) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("First Person Charecter is Jumping!"));
	}

}

// Perform the Character Movement
void AFirstPersonCharacter::KB_GamepadMove(const FInputActionInstance& Instance)
{
	FVector2D AxisValue = Instance.GetValue().Get<FVector2D>();
	float FloatValue = Instance.GetValue().Get<float>();
	// Add Threshhold to Avoid Unwanted Movements
	if (abs(AxisValue[0]) > 0.5 || abs(AxisValue[1]) > 0.5)
	{
		AddMovementInput(GetActorForwardVector(), -AxisValue[0]);
		AddMovementInput(GetActorRightVector(), AxisValue[1]);
	}
}

// Perform the Character Rotation
void AFirstPersonCharacter::KB_GamepadRotation(const FInputActionInstance& Instance)
{
	FVector2D AxisValue = Instance.GetValue().Get<FVector2D>();
	float FloatValue = Instance.GetValue().Get<float>();
	// Add Threshhold to Avoid Unwanted Rotations
	if (abs(AxisValue[0]) > 0.5 || abs(AxisValue[1]) > 0.5)
	{
		AddControllerYawInput(20 * AxisValue[0] * GetWorld()->GetDeltaSeconds());
		AddControllerPitchInput(-20 * AxisValue[1] * GetWorld()->GetDeltaSeconds());
	}
}

// Teleport Character 100 Units Forward
void AFirstPersonCharacter::KB_GamepadL1(const FInputActionInstance& Instance)
{
	bool BoolValue = Instance.GetValue().Get<bool>();
	if (BoolValue)
	{
		//AddMovementInput(GetActorForwardVector(), 100);
		TeleportTo(FVector(GetActorLocation().X - 100, GetActorLocation().Y, GetActorLocation().Z), FRotator());

	}

}

// Teleport Character 100 Units to the Right
void AFirstPersonCharacter::KB_GamepadR1(const FInputActionInstance& Instance)
{
	bool BoolValue = Instance.GetValue().Get<bool>();
	if (BoolValue)
	{
		//AddMovementInput(GetActorRightVector(), 100);
		TeleportTo(FVector(GetActorLocation().X, GetActorLocation().Y - 100, GetActorLocation().Z), FRotator());

	}

}
	
// Teleport Character 100 Units in the Sky
void AFirstPersonCharacter::KB_GamepadL2(const FInputActionInstance& Instance)
{
	bool BoolValue = Instance.GetValue().Get<bool>();
	if (BoolValue)
	{
		TeleportTo(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 100), FRotator());
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("L2!"));
	}

}

// Called to bind functionality to input
void AFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	Super::PawnClientRestart();

	if (ULocalPlayer* LocalPlayer = Cast<APlayerController>(Controller)->GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (!IMC_Normal_Controls.IsNull()) 
			{
				InputSystem->AddMappingContext(IMC_Normal_Controls.LoadSynchronous(), 1);
			}
		}
	}

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	// You can bind to any of the trigger events here by changing the "ETriggerEvent" enum value
	Input->BindAction(IA_KB_Move_InOut, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::KB_Move_InOut);
	Input->BindAction(IA_KB_Move_LeftRight, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::KB_Move_LeftRight);
	Input->BindAction(IA_KB_Look_UpDown, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::KB_Look_UpDown);
	Input->BindAction(IA_KB_Look_LeftRight, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::KB_Look_LeftRight);
	Input->BindAction(IA_KB_Jump, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::KB_Jump);
	Input->BindAction(IA_KB_GamepadMove, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::KB_GamepadMove);
	Input->BindAction(IA_KB_GamepadRotation, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::KB_GamepadRotation);
	Input->BindAction(IA_KB_GamepadL1, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::KB_GamepadL1);
	Input->BindAction(IA_KB_GamepadR1, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::KB_GamepadR1);
	Input->BindAction(IA_KB_GamepadL2, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::KB_GamepadL2);

}

