#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

class UStaticMeshComponent;

UCLASS()
class RADIALTRIGGER_API ABall : public AActor
{
	GENERATED_BODY()

public:
	ABall();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BallMesh;
};