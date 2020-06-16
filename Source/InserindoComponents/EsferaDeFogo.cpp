// Fill out your copyright notice in the Description page of Project Settings.


#include "EsferaDeFogo.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/TextRenderComponent.h"


// Sets default values
AEsferaDeFogo::AEsferaDeFogo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Cria uma instancia de uma USphereCompoent que será apontada por EsferaDeColisao
	EsferaDeColisao = CreateDefaultSubobject<USphereComponent>(TEXT("Raiz"));

	// Define o tamanho(Raio) da esfera
	EsferaDeColisao->InitSphereRadius(100.f);

	// Define o perfil de colisão como OverlapAllDynamic (SOBREPOSIÇÃO)
	EsferaDeColisao->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	RootComponent = EsferaDeColisao; // Indica que EsferaDeColisao será o componente Raiz da hierarquia de componentes

	// Cria uma static mesh component e coloca o endereço de memoria deste recurso no ponteiro EsferaVisivel
	EsferaVisivel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Esfera"));

	// Cria um compoente de particula e coloca endereço de memória no ponteiro
	ParticulaDeFogo = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particula Fogo"));
	ParticulaDeFogo->SetupAttachment(EsferaVisivel); // Coloca este compoente como filho de EsferaVisivel
	ParticulaDeFogo->bAutoActivate = true; // Ativa a particula quando iniciado o jogo

	// Cria o componente de texto de exibição
	TextoDeExibicao = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Texto"));
	TextoDeExibicao->SetupAttachment(EsferaVisivel); // Anexa o componente de texto em esfera visivel como filho
	TextoDeExibicao->SetRelativeLocation(FVector(0.f, 0.f, 110.f)); // Define a posição em relação a posição do elemento PAI
	TextoDeExibicao->SetHorizontalAlignment(EHTA_Center); // Define que será centralizado
	TextoDeExibicao->SetYScale(1.f); // Define a escala em 1.f no eixo Y
	TextoDeExibicao->SetXScale(1.f); // Define a escala em 1.f no eixo X
	TextoDeExibicao->SetText(FText::FromString("C++ na Unreal Udemy")); // Define o texto convertendo de String para FText
	TextoDeExibicao->SetTextRenderColor(FColor::Red); // Define a cor do texto
	TextoDeExibicao->SetVisibility(true); // Inicia de forma visível

	// Quando o evento de overlap ocorrer a função OnActorDeginOverlp é acionada 
	// AddDynamic está anexando a função IniciouSobreposicao para que esta função também seja executada após ocorrer o evento de Overpad
	// e que chama a fun~ção OnActorBeginOverlap, chamado de DELEGATE.
	// Dentro de OnActorBeginOverlap vai ocorrer uma chamada de todas as funções vinculadas(AddDynamic) a ela. Isso é feito via função Brodcast.
	OnActorBeginOverlap.AddDynamic(this, &AEsferaDeFogo::IniciouSobreposicao);

	// Também está anexada, vinculando a função TerminouSobreposicao.
	OnActorEndOverlap.AddDynamic(this, &AEsferaDeFogo::TerminouSobreposicao);

	// Atribui Shape_Sphere ao UStaticMesh de EsferaVisivel
	ConstructorHelpers::FObjectFinder<UStaticMesh>
		Esfera(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	
	// Atribui o material M_Metal_Gold a esfera
	ConstructorHelpers::FObjectFinder<UMaterialInterface>
		MaterialEsfera(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'"));

	// Atribui a particula P_Fire ao sistema de particula da esfera
	ConstructorHelpers::FObjectFinder<UParticleSystem>
		Fogo(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));

	// Se todos os recursos forem encontrados então segue
    if(Esfera.Succeeded() && MaterialEsfera.Succeeded() && Fogo.Succeeded()) {
		EsferaVisivel->SetStaticMesh(Esfera.Object); // Seta que o staticMesh de Esfera Visivel será Esfera.Object
		EsferaVisivel->SetMaterial(0, MaterialEsfera.Object); // Seta que o material de Esfera Visível será MaterialEsfera.Object
		ParticulaDeFogo->SetTemplate(Fogo.Object); // Seta que o sistema de particula de Esfera Visível será Fogo.Object
		EsferaVisivel->SetRelativeLocation(FVector(0.f, 0.f, -60.f)); // Seta que a EsferaVisivel tera a localização x=0, y=0, z=-60
	}

	// Anexa este componente como sendo filho do componente raiz (neste caso será EsferaDeColisao)
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

void AEsferaDeFogo::IniciouSobreposicao(AActor* OverlappedActor, AActor* OtherActor) {
	FString StringDeSaida;
	StringDeSaida = "Sobrepondo " + OtherActor->GetName() + " !";
	TextoDeExibicao->SetText(FText::FromString(StringDeSaida));
}

void AEsferaDeFogo::TerminouSobreposicao(AActor* OverlappedActor, AActor* OtherActor) {
	TextoDeExibicao->SetText(FText::FromString(TEXT("Deixei de sobrepor")));
}
