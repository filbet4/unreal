#include "Tracker.h"

ATracker::ATracker()
{
	PrimaryActorTick.bCanEverTick = true;
	TrackerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("trackerMesh"));
	RootComponent = TrackerMesh;
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(RootComponent);
}

void ATracker::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATracker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

