// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "FirstPersonCharacter.generated.h"


class UCameraComponent;
class UInputAction;
class UInputMappingContext;

UCLASS()

class ASSIGNMENT1_API AFirstPersonCharacter : public ACharacter
{
	GENERATED_BODY()

#pragma region input

		UPROPERTY(EditAnywhere, Category = "Components | Camera")
		UCameraComponent* camera;

		UPROPERTY(EditAnywhere, Category = "Input | Actions")
			UInputAction* IA_KB_Move_InOut;
		UPROPERTY(EditAnywhere, Category = "Input | Actions")
			UInputAction* IA_KB_Move_LeftRight;
		UPROPERTY(EditAnywhere, Category = "Input | Actions")
			UInputAction* IA_KB_Look_UpDown;
		UPROPERTY(EditAnywhere, Category = "Input | Actions")
			UInputAction* IA_KB_Look_LeftRight;
		UPROPERTY(EditAnywhere, Category = "Input | Actions")
			UInputAction* IA_KB_Jump;
		UPROPERTY(EditAnywhere, Category = "Input | Actions")
			UInputAction* IA_KB_GamepadMove;
		UPROPERTY(EditAnywhere, Category = "Input | Actions")
			UInputAction* IA_KB_GamepadRotation;
		UPROPERTY(EditAnywhere, Category = "Input | Actions")
			UInputAction* IA_KB_GamepadL1;
		UPROPERTY(EditAnywhere, Category = "Input | Actions")
			UInputAction* IA_KB_GamepadR1;
		UPROPERTY(EditAnywhere, Category = "Input | Actions")
			UInputAction* IA_KB_GamepadL2;

		UPROPERTY(EditAnywhere, Category = "Input")
			TSoftObjectPtr<UInputMappingContext> IMC_Normal_Controls;

public:
	// Sets default values for this character's properties
	AFirstPersonCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void KB_Move_InOut(const FInputActionInstance& Instance);

	void KB_Move_LeftRight(const FInputActionInstance& Instance);

	void KB_Look_UpDown(const FInputActionInstance& Instance);

	void KB_Look_LeftRight(const FInputActionInstance& Instance);

	void KB_Jump(const FInputActionInstance& Instance);

	void KB_GamepadMove(const FInputActionInstance& Instance);

	void KB_GamepadRotation(const FInputActionInstance& Instance);

	void KB_GamepadL1(const FInputActionInstance& Instance);

	void KB_GamepadR1(const FInputActionInstance& Instance);

	void KB_GamepadL2(const FInputActionInstance& Instance);

};
