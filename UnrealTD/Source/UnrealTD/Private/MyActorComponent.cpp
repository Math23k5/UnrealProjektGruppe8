// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorComponent.h"

// Sets default values for this component's properties
UMyActorComponent::UMyActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	DefaultHealth = 100;
	Health = DefaultHealth;
}


// Called when the game starts
void UMyActorComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();

	if (Owner)
	{
		Owner->OnTakeAnyDamage.AddDynamic(this, &UMyActorComponent::TakeDamage);
	}
	
}

void UMyActorComponent::TakeDamage(AActor* DamageActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0)
	{
		return;
	}

	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);

}



