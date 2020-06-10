// Fill out your copyright notice in the Description page of Project Settings.


#include "EsferaDeFogo.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AEsferaDeFogo::AEsferaDeFogo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Cria uma instancia de uma USphereCompoent que ser� apontada por EsferaDeColisao
	EsferaDeColisao = CreateDefaultSubobject<USphereComponent>(TEXT("Raiz"));

	// Define o tamanho(Raio) da esfera
	EsferaDeColisao->InitSphereRadius(100.f);

	// Define o perfil de colis�o como OverlapAllDynamic (SOBREPOSI��O)
	EsferaDeColisao->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	RootComponent = EsferaDeColisao; // Indica que EsferaDeColisao ser� o componente Raiz da hierarquia de componentes

	// Cria uma static mesh component e coloca o endere�o de memoria deste recurso no ponteiro EsferaVisivel
	EsferaVisivel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Esfera"));

	// Anexa este componente como sendo filho do componente raiz (neste caso ser� EsferaDeColisao)
	EsferaVisivel->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEsferaDeFogo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEsferaDeFogo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

