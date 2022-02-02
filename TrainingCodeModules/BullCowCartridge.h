// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:		//Global classes
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;
	void SetupGame();							//added initialization game
	void EndGame();
	void ProcessGuess(FString Guess);

	// Your declarations go below! THIS are member variables
	private: 
	FString HiddenWord;		//the variable fstring hiddenword is moved in the header file here.
	int32 Lives; 			//NOTICE Unreal engine has its own data types here for example instead of regular integer "int" it is "int32" in UE
	bool bGameOver;
};
