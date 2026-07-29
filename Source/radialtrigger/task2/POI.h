#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "POI.generated.h"

class ATracker;
class UStaticMeshComponent;
class UMaterialInstanceDynamic;
class UMaterialInterface;

UCLASS()
class RADIALTRIGGER_API APOI : public AActor
{
	GENERATED_BODY()
	
public:	
	APOI();
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* POIMesh;

	UPROPERTY(EditAnywhere)
	ATracker* tracker;
	
	UPROPERTY(EditAnywhere)
	UMaterialInterface* Material;
	
	UMaterialInstanceDynamic* DynamicMaterial;
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
