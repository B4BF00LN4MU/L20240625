// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.generated.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>
		(PlayerInputComponent);
	if (EIC)
	{
		EIC->BindAction(IA_Forward, ETriggerEvent::Triggered, this, &AMyCharacter::Move);
		EIC->BindAction(IA_MyJump, ETriggerEvent::Triggered, this, &AMyCharacter::Jump);
		EIC->BindAction(IA_MyJump, ETriggerEvent::Triggered, this, &AMyCharacter::Look);
		EIC->BindAction(IA_MyJump, ETriggerEvent::Triggered, this, &AMyCharacter::Zoom);

	}
}

void AMyCharacter::Move(const FInputActionValue& Value)
{
	FVector2D Direction = Value.Get<float>();

	AddMovementInput(
		GetActorForwardVector() * Direction.X
	);

	AddMovementInput(
		GetActorForwardVector() * Direction.Y
	);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
	              
}

void AMyCharacter::Look(const FInputActionValue& Value)
{
	FVector2D Rotation = Value.Get<FVector2D>();

	AddControllerYawInput(Rotation.X);
	AddControllerPitchInput(Rotation.Y);
}

void AMyCharacter::Zoom(const FInputActionValue& Value)
{
	float ZoomDepth = Value.Get<FVector>();
	CameraBoom->TargetArmLength = CameraBoom->TargetArmLength + (ZoomDepth * 500.0f);

	CameraBoom->TargetArmLength = FMath::FInterpTo(CameraBoom->TargetArmLength, NewTargetLength, UGameplayStatics::GetWorldDeltaSeconds(GetWorld()), 1.0f);

	CameraBoom->TargetArmLength = FMath::Clamp(CameraBoom->TargetArmLength, 40.0f, 600.0f);

}

