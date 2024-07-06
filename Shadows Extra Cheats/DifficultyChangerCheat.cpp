#include "stdafx.h"
#include "DifficultyChangerCheat.h"
#include <Spore\Simulator\SubSystem\ToolManager.h>
#include <Spore\Simulator\cPlayer.h>

using namespace ArgScript;
using namespace Simulator;
using namespace App;

DifficultyChangerCheat::DifficultyChangerCheat()
{
}


DifficultyChangerCheat::~DifficultyChangerCheat()
{
}

int Gamemode = 2;
bool IsTrue = true;


void DifficultyChangerCheat::ParseLine(const ArgScript::Line& line)
{
	if (!Simulator::IsSpaceGame()) {
		App::ConsolePrintF("You must be on Space Stage to use this cheat.");
		return;
	}

	GetPlayerUFO()->SetHealthPoints(2249);

	auto player = GameNounManager.GetPlayer();
	App::ConsolePrintF("%i", player->mDifficultyLevel);

	auto args = line.GetArguments(1);

	player->mDifficultyLevel = (Difficulty)mpFormatParser->ParseInt(args[0]);


	//Simulator::cGameModeManager::GetDifficultyTuning(Gamemode, IsTrue);
	// Simulator::cPlaceColonyToolStrategy::OnSelect(cSpaceToolData * pTool);



}

const char* DifficultyChangerCheat::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "Allows you to change the difficulty in game memory! (MUST SAVE AND RELOAD TO TAKE EFFECT)";
	}
	else {
		return "difficultyChanger: Allows you to change the difficulty in game memory! (MUST SAVE AND RELOAD TO TAKE EFFECT)";
	}
}
