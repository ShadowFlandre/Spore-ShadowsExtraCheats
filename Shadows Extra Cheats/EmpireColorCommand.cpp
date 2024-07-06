#include "stdafx.h"
#include "EmpireColorCommand.h"
#include <Spore\Simulator\cEmpire.h>
#include <Spore\Simulator\cIdentityColorable.h>

using namespace ArgScript;
using namespace Simulator;
using namespace App;

EmpireColorCommand::EmpireColorCommand()
{
}


EmpireColorCommand::~EmpireColorCommand()
{
}

void EmpireColorCommand::ParseLine(const ArgScript::Line& line)
{
	string InputString;
	//Check for Space stage to avoid crash
	if (!Simulator::IsSpaceGame()) {
		App::ConsolePrintF("You must be on Space Stage to use this cheat.");
		return;
	}

	//Get player empire and fetch mCachedColor
	auto playerEmpire = Simulator::GetPlayerEmpire();
	auto player = GameNounManager.GetPlayer();
	//Take in arguments from the input.
	auto args = line.GetArguments(3);
	float iR = mpFormatParser->ParseFloat(args[0]);
	float iG = mpFormatParser->ParseFloat(args[1]);
	float iB = mpFormatParser->ParseFloat(args[2]);
	//Use operand to change color variable into the parsed input
	auto InputColor = playerEmpire->mCachedColor.Set(iR, iG, iB);
	App::ConsolePrintF("Color now updated to: (%f, %f, %f)", InputColor.r, InputColor.g, InputColor.b);
}

const char* EmpireColorCommand::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "Changes your empire color based on 3 float inputs between 0-1!";
	}
	else {
		return "changeEmpireColorCache: Changes your empire color based on 3 float inputs between 0-1!";
	}
}
