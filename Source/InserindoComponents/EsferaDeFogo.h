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
	// ----------------------------------------------------------------------------------------------------------------------
	// UPROPERTY: Permite que a vari�vel possa ser visualizada ou alterada via editor da Unreal ou na Blueprint
	// Especificadores: N�vel de acesso / Utiliza��o desejado da vari�vel no editor da Unreal ou na Blueprint

	// Category = "Nome" - Permite agrupar vari�veis em uma �nica se��o dentro do editor da Unreal e/ou dentro da Blueprint.
	// Quando o usu�rio procurar editar esta vari�vel no editor ou na Blueprint, aparece sob o t�tulo "Nome".
	// ----------------------------------------------------------------------------------------------------------------------

	// Edit�vel em (editor da unreal, editor da blueprint)
	// OBS: N�o fica dispon�vel no Event Graph da Blueprint
	UPROPERTY(EditAnywhere, Category = "Variaveis")
		bool VariavelEditAnywhere;

	// Vari�vel vis�vel na janela de Detalhes o editor e na janela de detalhes da Blueprint mas N�O PODER� SER EDITADA.
	// OBS: N�o fica dispon�vel no Event Graph da Blueprint
	UPROPERTY(VisibleAnywhere, Category = "Variaveis")
		float VariavelVisibleAnywhere;

	// Pode-se definir um valor padr�o para a vari�vel apenas na janela da Blueprint ANTES da execu��o do jogo.
	// OBS: N�O fica acess�vel dentro do editor da Unreal e nem no Event Graph da Blueprint.
	UPROPERTY(EditDefaultsOnly, Category = "Variaveis")
		float VariavelEditDefaulOnly;

	// Vari�vel vis�vel na janela de pripriedades do editor e na janela de detalhes da Blueprint.
	// OBS: N�o poder� ser editada.
	UPROPERTY(VisibleDefaultsOnly, Category = "Variaveis")
		float VariavelVisibleDefaultsOnly;

	// Permite que a vari�vel seja lida ou modificada apenas de dentro de Event Graph da Blueprint(Get e Set)
	// OBS: N�o dispon�vel no editor da Unreal NEM no editor da Blueprint.
	UPROPERTY(BlueprintReadWrite, Category = "Variaveis")
		FVector VariavelBlueprintReadWrite = FVector(0.f, 0.f, -180.f);

	// Permite que a vari�vel seja lida (Get) apenas de dentro do Event Graph da Blueprint.
	// OBS: N�o dispon�vel no editor da Unreal nem no editor da Blueprint.
	UPROPERTY(BlueprintReadOnly, Category = "Variaveis")
		FString VariavelBlueprintReadOnly = "Texto Blueprint";

	// Usando mais de um especificador
	// OBS: Vis�vel no edito da unrea / Event Graph e Blueprint
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variaveis")
		FString VariavelEditAnywhereBlueprintReadWrite = "Texto Edit�vel";

	// Usando mais de um especificador
	// OBS: Vis�vel no edito da unrea / Event Graph e Blueprint
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Variaveis")
		FString VariavelEditAnywhereBlueprintReadOnly = "Outro Texto";

	/*
	 Macro UFUNCTION define fun��es e pode receber par�metros, informa a Unreal Engine que sua fun��o declarada estar�
	 dispon�vel para um uso mais amplo dentro do editor Blueprint Scripting.
	 Pode-se incluir especificadores como par�metros para UFUNCTION() para determinar n�vel de acesso que voc� est�
	 disposto a dar na sua fun��o.
	 1. BluprintCallable:
			|__ A funcao pode ser executada em uma Blueprint. Isso permite que a fun��o seja chamada em scripts de Blueprints.
	 2. BlueprintImplementableEvent:
			|__ Indica que a funcao pode ser substituida em uma Blueprint, nesse caso, a Blueprint impplementa a logica dessa funcao em vez do codigo C++. Pode ser combinado com BlueprintCalleble para que ee possa ser chamado na Blueprint, caso contrario, apenas C++ pode chamar essa funcao. Se n�o houver implementa��o da fun��o na blueprint(ou sej, se a blueprint n�o substituir a fun��o), a chamada de fun��o no codigo C++ seja ignorado.
	 3. BlueprintNativeEvent
			|__ Quase a mesma coisa que BlueprintImplementableEvent, por�m, se n�o houver implementa��o da fun��o na Blueprint(ou seja se a blueprint n�o substituir a funcao), voc� pode especificar uma funcao C++ que sera chamada caso nenhuma substituicao tiver sdo definida na bluprint. Para cada BlueprintNativeEvent que voce defini, voce deve incluir uma versao de implementacao no C++ como o seguinte formato [NomeFuncao]_Implementation(mesma lista de parametros).
	 4. BlueprintPure
			|__
	
	*/

	UFUNCTION(BlueprintNativeEvent)
		void IniciouSobreposicao(AActor* OverlappedActor, AActor* OtherActor);
		// Essa fun��o ser� chamado caso a blueprint n�o sobrescreva essa fun��o.
		void IniciouSobreposicao_Implementation(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION(BlueprintNativeEvent)
		void TerminouSobreposicao(AActor* OverlappedActor, AActor* OtherActor);
		// Essa fun��o ser� chamado caso a blueprint n�o sobrescreva essa fun��o.	
		void TerminouSobreposicao_Implementation(AActor* OverlappedActor, AActor* OtherActor);

	// Deve ser implementado na bluprint
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Sobreposicoes")
		void ImplementePraMimBlueprint();

	// forward declaration
	// Precisamos de class para indicar que apesar da classe n�o esta ainda presente ela ser� posteriormente anexada ao projeto.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Texto");
	class UTextRenderComponent* TextoDeExibicao;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
