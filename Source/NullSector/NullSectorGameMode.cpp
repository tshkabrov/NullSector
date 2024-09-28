// Copyright Epic Games, Inc. All Rights Reserved.

#include "NullSectorGameMode.h"
#include "NullSectorCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANullSectorGameMode::ANullSectorGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
