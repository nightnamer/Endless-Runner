// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/Actor.h"
#include "PlatformObsticle.generated.h"

UCLASS()
class ENDLESSRUNNER_API APlatformObsticle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformObsticle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FVector StartPosition;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite)
	FVector Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UArrowComponent* Arrows;
	
	UFUNCTION(BlueprintCallable)
	static float GetStaticMeshSize(class UStaticMesh* Mesh);
};
