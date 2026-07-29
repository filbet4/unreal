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
	UE_LOG(LogTemp, Warning, TEXT("POI BeginPlay"));
	Super::BeginPlay();
	if (Material)
	{
		DynamicMaterial = UMaterialInstanceDynamic::Create(Material, this);
		POIMesh->SetMaterial(0, DynamicMaterial);
	}

}

void APOI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(!tracker)
	{
		return;
	}
	FVector Direction = (GetActorLocation() - tracker->GetActorLocation()).GetSafeNormal();
	FVector Forward = tracker->GetActorForwardVector();

	float dot = FVector::DotProduct(Direction, Forward);
	
	const float edge = 0.1f;

	if (dot > edge)
	{
		DynamicMaterial->SetVectorParameterValue(TEXT("color"), FLinearColor::Green);
	}
	else if (dot < -edge)
	{
		DynamicMaterial->SetVectorParameterValue(TEXT("color"), FLinearColor::Red);
	}
	else
	{
		DynamicMaterial->SetVectorParameterValue(TEXT("color"), FLinearColor::Yellow);
	}
	
}

