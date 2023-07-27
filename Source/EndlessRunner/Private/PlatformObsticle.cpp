// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformObsticle.h"

// Sets default values
APlatformObsticle::APlatformObsticle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlatformObsticle::BeginPlay()
{
	Super::BeginPlay();

	StartPosition = GetActorLocation();
	
}

// Called every frame
void APlatformObsticle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector MyLoc = GetActorLocation();
	FVector NewLoc = MyLoc + Speed;
	SetActorLocation(NewLoc);

	float dist = FVector::Distance(StartPosition,MyLoc);
	if(dist > 12000)
	{
		Destroy();
	}
}

float APlatformObsticle::GetStaticMeshSize(class UStaticMesh* Mesh)
{
	if (!Mesh)
		return 0;


	return Mesh->GetBounds().GetBox().GetSize().X;
}