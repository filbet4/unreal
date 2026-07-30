#include "POI.h"
#include "Tracker.h"
APOI::APOI()
{
	PrimaryActorTick.bCanEverTick = true;
	POIMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("POIMesh"));
	RootComponent = POIMesh;
}

void APOI::BeginPlay()
{
	Super::BeginPlay();
	if (Material)
	{
		DynamicMaterial = UMaterialInstanceDynamic::Create(Material, this);
		POIMesh->SetMaterial(0, DynamicMaterial);
	}
	StartLocation = GetActorLocation();	
}

void APOI::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!tracker || !DynamicMaterial)
    {
        return;
    }

    RunningTime += DeltaTime;

    FVector NewLocation = StartLocation;
    NewLocation.X += FMath::Cos(RunningTime * Speed) * Amplitude;
    NewLocation.Y += FMath::Sin(RunningTime * Speed) * Amplitude;
    SetActorLocation(NewLocation);

    FVector Direction =
        (GetActorLocation() - tracker->GetActorLocation()).GetSafeNormal();

    FVector Forward = tracker->GetActorForwardVector();

    float dot = FVector::DotProduct(Direction, Forward);

    float T = (dot + 1.f) * 0.5f;

    FLinearColor Color;

    if (T < 0.5f)
    {
        Color = FLinearColor::LerpUsingHSV(
            FLinearColor::Red,
            FLinearColor::Yellow,
            T * 2.f);
    }
    else
    {
        Color = FLinearColor::LerpUsingHSV(
            FLinearColor::Yellow,
            FLinearColor::Green,
            (T - 0.5f) * 2.f);
    }

    DynamicMaterial->SetVectorParameterValue(ColorParameter, Color);
}



