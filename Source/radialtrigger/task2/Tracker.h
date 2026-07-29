#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tracker.generated.h"

class UStaticMeshComponent;
UCLASS()
class RADIALTRIGGER_API ATracker : public AActor
{
	GENERATED_BODY()
	
public:	
	ATracker();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* TrackerMesh;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
