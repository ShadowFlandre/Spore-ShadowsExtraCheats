#include "stdafx.h"
#include "ResetPlanetScripts.h"

ResetPlanetScripts::ResetPlanetScripts()
{
}


ResetPlanetScripts::~ResetPlanetScripts()
{
}


void ResetPlanetScripts::ParseLine(const ArgScript::Line& line)
{
	ResourceKey myKey(0x05528DB9, 0x05528D58, 0x40A00200);  // This will get the filename you would want to delete. The path must be specified in order of name, type, folder.
	auto database = ResourceManager.FindDatabase(myKey);
	database->DeleteRecord(myKey);
	App::ConsolePrintF("Planet Scripts have been reset! You must restart the game, execute the command in galaxy, and restart the game again for the changes to take place!");
}

const char* ResetPlanetScripts::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "This cheat resets the planet scripts! THIS CANNOT BE UNDONE! PLEASE BACK UP YOUR SAVE FILE BEFORE USING THIS COMMAND!";
	}
	else {
		return "resetPlanetScripts: This cheat resets the planet scripts! THIS CANNOT BE UNDONE! PLEASE BACK UP YOUR SAVE FILE BEFORE USING THIS COMMAND!";
	}
}
