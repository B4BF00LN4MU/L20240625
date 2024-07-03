// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class L20240625_API AMyHUD : public AHUD
{
	GENERATED_BODY()
public:
	AMyHUD();
	virtual void DrawHUD() override;
	int32 GetCenterX();
	void SetCenterX(int32 SetCenterX);

	int32 GetCenterY();
	void SetCenterY(int32 SetCenterY);

	int32 GetCrosshairSize();
	void SetCrosshairSize(int32 SetCrosshairSize);

	float GetCrosshiarOpen();
	void SetCrosshiarOpen(float SetCrosshairOpen);

protected:
	int32 CenterX;
	int32 CenterY;
	int32 CrosshairSize;
	float CrosshairOpen;
};
