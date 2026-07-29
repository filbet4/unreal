#include "Ring.h"
#include "Ball.h"

#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"

ARing::ARing()
{
	PrimaryActorTick.bCanEverTick = true;

	RingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RingMesh"));
	RootComponent = RingMesh;
}

void ARing::BeginPlay()
{
	Super::BeginPlay();
}

void ARing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Ball)
	{
		return;
	}

	float DistanceX = GetActorLocation().X - Ball->GetActorLocation().X;
	float DistanceY = GetActorLocation().Y - Ball->GetActorLocation().Y;
	float Distance = sqrt(pow(DistanceX, 2) + pow(DistanceY, 2));

	if (Distance <= Radius)
	{
		RingMesh->SetMaterial(0, Green);
	}
	else
	{
		RingMesh->SetMaterial(0, Red);
	}
}