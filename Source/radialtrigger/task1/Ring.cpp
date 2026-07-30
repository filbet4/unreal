#include "Ring.h"
#include "Ball.h"

#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstanceDynamic.h"

ARing::ARing()
{
	PrimaryActorTick.bCanEverTick = true;

	RingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RingMesh"));
	RootComponent = RingMesh;
}

void ARing::BeginPlay()
{
	Super::BeginPlay();

	if (Material)
	{
		DynamicMaterial = UMaterialInstanceDynamic::Create(Material, this);
		RingMesh->SetMaterial(0, DynamicMaterial);
		DynamicMaterial->SetVectorParameterValue(TEXT("color"), FLinearColor::Blue);
	}
}

void ARing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Ball || !DynamicMaterial)
	{
		return;
	}
	FVector RingLocation = GetActorLocation();
	FVector BallLocation = Ball->GetActorLocation();

	float DX = RingLocation.X - BallLocation.X;
	float DY = RingLocation.Y - BallLocation.Y;

	float DistanceSquared = DX * DX + DY * DY;
	float RadiusSquared = Radius * Radius;


	if (DistanceSquared <= RadiusSquared)
	{
		DynamicMaterial->SetVectorParameterValue(ColorParameter, FLinearColor::Green);
	}
	else
	{
		DynamicMaterial->SetVectorParameterValue(ColorParameter, FLinearColor::Red);
	}
}