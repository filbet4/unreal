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

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* RingMesh;

public:

	UPROPERTY(EditAnywhere)
	ABall* Ball;

	UPROPERTY(EditAnywhere)
	float Radius = 300.f;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* Green;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* Red;
};