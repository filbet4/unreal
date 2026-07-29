#include "Ball.h"
#include "Components/StaticMeshComponent.h"

ABall::ABall()
{
	PrimaryActorTick.bCanEverTick = false;

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	RootComponent = BallMesh;
}