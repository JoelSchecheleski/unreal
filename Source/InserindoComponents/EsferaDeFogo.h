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

	// Ponteiro para um componente de sistema de particula
	UPROPERTY(EditAnywhere, Category = "Componentes")
		UParticleSystemComponent* ParticulaDeFogo;

protected:
	// ----------------------------------------------------------------------------------------------------------------------
	// UPROPERTY: Permite que a variável possa ser visualizada ou alterada via editor da Unreal ou na Blueprint
	// Especificadores: Nível de acesso / Utilização desejado da variável no editor da Unreal ou na Blueprint

	// Category = "Nome" - Permite agrupar variáveis em uma única seção dentro do editor da Unreal e/ou dentro da Blueprint.
	// Quando o usuário procurar editar esta variável no editor ou na Blueprint, aparece sob o título "Nome".
	// ----------------------------------------------------------------------------------------------------------------------

	// Editável em (editor da unreal, editor da blueprint)
	// OBS: Não fica disponível no Event Graph da Blueprint
	UPROPERTY(EditAnywhere, Category = "Variaveis")
		bool VariavelEditAnywhere;

	// Variável visível na janela de Detalhes o editor e na janela de detalhes da Blueprint mas NÃO PODERÁ SER EDITADA.
	// OBS: Não fica disponível no Event Graph da Blueprint
	UPROPERTY(VisibleAnywhere, Category = "Variaveis")
		float VariavelVisibleAnywhere;

	// Pode-se definir um valor padrão para a variável apenas na janela da Blueprint ANTES da execução do jogo.
	// OBS: NÃO fica acessível dentro do editor da Unreal e nem no Event Graph da Blueprint.
	UPROPERTY(EditDefaultsOnly, Category = "Variaveis")
		float VariavelEditDefaulOnly;

	// Variável visível na janela de pripriedades do editor e na janela de detalhes da Blueprint.
	// OBS: Não poderá ser editada.
	UPROPERTY(VisibleDefaultsOnly, Category = "Variaveis")
		float VariavelVisibleDefaultsOnly;

	// Permite que a variável seja lida ou modificada apenas de dentro de Event Graph da Blueprint(Get e Set)
	// OBS: Não disponível no editor da Unreal NEM no editor da Blueprint.
	UPROPERTY(BlueprintReadWrite, Category = "Variaveis")
		FVector VariavelBlueprintReadWrite = FVector(0.f, 0.f, -180.f);

	// Permite que a variável seja lida (Get) apenas de dentro do Event Graph da Blueprint.
	// OBS: Não disponível no editor da Unreal nem no editor da Blueprint.
	UPROPERTY(BlueprintReadOnly, Category = "Variaveis")
		FString VariavelBlueprintReadOnly = "Texto Blueprint";

	// Usando mais de um especificador
	// OBS: Visível no edito da unrea / Event Graph e Blueprint
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variaveis")
		FString VariavelEditAnywhereBlueprintReadWrite = "Texto Editável";

	// Usando mais de um especificador
	// OBS: Visível no edito da unrea / Event Graph e Blueprint
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Variaveis")
		FString VariavelEditAnywhereBlueprintReadOnly = "Outro Texto";

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
