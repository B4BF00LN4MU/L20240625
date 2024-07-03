// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"

AMyHUD::AMyHUD()
{

}

void AMyHUD::DrawHUD()
{
	GetOwningPlayerController()->GetViewportSize(CenterX, CenterY);
	CenterX /= 2;
	CenterY /= 2;
}

int AMyHUD::GetCenterX()
{
	return CenterX;
}

void AMyHUD::SetCenterX(int32 SetCenterX)
{
	CenterX = SetCenterX;
}

int AMyHUD::GetCenterY()
{
	return CenterY;
}

void AMyHUD::SetCenterY(int32 SetCenterY)
{
	CenterY = SetCenterY;
}

int AMyHUD::GetCrosshairSize()
{
	return CrosshairSize;
}

void AMyHUD::SetCrosshairSize(int32 SetCrosshairSize)
{
	CrosshairSize = SetCrosshairSize;
}

float AMyHUD::GetCrosshiarOpen()
{
	return CrosshairOpen;
}

void AMyHUD::SetCrosshiarOpen(float SetCrosshairOpen)
{
	CrosshairOpen = SetCrosshairOpen;
}