#include "stdafx.h"
#include <windows.h>
#include "RenamePlanetCommand.h"

using namespace ArgScript;
using namespace Simulator;
using namespace App;

RenamePlanetCommand::RenamePlanetCommand()
{
}


RenamePlanetCommand::~RenamePlanetCommand()
{
}

void RenamePlanetCommand::ParseLine(const ArgScript::Line& line)
{
	//Check for Space stage to avoid crash
	if (!Simulator::IsSpaceGame()) {
		App::ConsolePrintF("You must be on Space Stage to use this cheat.");
		return;
	}
	auto args = line.GetArguments(1);
	Simulator::GetActivePlanetRecord()->mName = ConvertToString16(args[0]); //Change name.
	App::ConsolePrintF("Renamed the planet to %s.", args[0]);
}

const char* RenamePlanetCommand::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "Forcefully renames a planet!";
	}
	else {
		return "renamePlanet: Forcefully renames a planet!";
	}
}
