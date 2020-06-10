// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EsferaDeFogo.generated.h"

UCLASS()
class INSERINDOCOMPONENTS_API AEsferaDeFogo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEsferaDeFogo();

private:
	// Declaração da viariável ponteiro EsferaVisivel capaz de receber um endereço de memória de um recurso do tipo UStaticMeshComponent.
	UPROPERTY(EditAnywhere, Category = "Componentes")
		UStaticMeshComponent* EsferaVisivel;

	// class indica que é forward declaration (declarando algo antes de sua utilização)
	UPROPERTY(EditAnywhere, Category = "Componentes")
		class USphereComponent* EsferaDeColisao;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
