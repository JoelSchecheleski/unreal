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
	// Declara��o da viari�vel ponteiro EsferaVisivel capaz de receber um endere�o de mem�ria de um recurso do tipo UStaticMeshComponent.
	UPROPERTY(EditAnywhere, Category = "Componentes")
		UStaticMeshComponent* EsferaVisivel;

	// class indica que � forward declaration (declarando algo antes de sua utiliza��o)
	UPROPERTY(EditAnywhere, Category = "Componentes")
		class USphereComponent* EsferaDeColisao;

	// Ponteiro para um componente de sistema de particula
	UPROPERTY(EditAnywhere, Category = "Componentes")
		UParticleSystemComponent* ParticulaDeFogo;

protected:
	UPROPERTY(EditAnywhere, Category = "Variaveis")
		bool VariavelEditAnywhere;

	UPROPERTY(EditAnywhere, Category = "Variaveis")
		float VariavelVisibleAnywhere;

	UPROPERTY(EditDefaultsOnly, Category = "Variaveis")
		float VariavelEditDefaulOnly;

	UPROPERTY(VisibleDefaultsOnly, Category = "Variaveis")
		float VariavelVisibleDefaultsOnly;

	UPROPERTY(BlueprintReadWrite, Category = "Variaveis")
		FVector VariavelBlueprintReadWrite = FVector(0.f, 0.f, -180.f);

	UPROPERTY(BlueprintReadOnly, Category = "Variaveis")
		FString VariavelBlueprintReadOnly = "Texto Blueprint";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variaveis")
		FString VariavelEditAnywhereBlueprintReadWrite = "Texto Edit�vel";

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Variaveis")
		FString VariavelEditAnywhereBlueprintReadOnly = "Outro Texto";

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
