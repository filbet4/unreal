#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ring.generated.h"

class ABall;
class UStaticMeshComponent;
class UMaterialInterface;

UCLASS()
class RADIALTRIGGER_API ARing : public AActor
{
	GENERATED_BODY()

public:
	ARing();

	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* RingMesh;

public:

	UPROPERTY(EditAnywhere)
	ABall* Ball;

	UPROPERTY(EditAnywhere)
	float Radius = 300.f;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* Material;

	UMaterialInstanceDynamic* DynamicMaterial;

	UPROPERTY(EditDefaultsOnly)
	FName ColorParameter = TEXT("color");

};