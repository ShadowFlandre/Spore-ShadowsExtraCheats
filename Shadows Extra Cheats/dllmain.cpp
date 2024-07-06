// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "DifficultyChangerCheat.h"
#include "RenamePlanetCommand.h"
#include "EmpireColorCommand.h"
#include "ResetPlanetScripts.h"

void Initialize()
{
	CheatManager.AddCheat("difficultyChanger", new DifficultyChangerCheat);
	CheatManager.AddCheat("renamePlanet", new RenamePlanetCommand);
	CheatManager.AddCheat("empireColor", new EmpireColorCommand);
	CheatManager.AddCheat("resetPlanetScripts", new ResetPlanetScripts);
}

void Dispose()
{
	// This method is called when the game is closing
}

member_detour(UpdateAndGetColor__detour, Simulator::cEmpire, ColorRGB& (ColorRGB&)) {
	ColorRGB detoured(ColorRGB & outputColor) {
		ColorRGB storedColorValue;
		if (this->mIDColorID == 0x53DBCF1) {
			original_function(this, outputColor);
			storedColorValue.r = mCachedColor.r;
			storedColorValue.g = mCachedColor.g;
			storedColorValue.b = mCachedColor.b;
			if (this == Simulator::GetPlayerEmpire()) {
				outputColor.Set(this->mCachedColor.r, this->mCachedColor.g, this->mCachedColor.b);
			}
			return outputColor;
		}
		else {
			original_function(this, outputColor);
		}
	}
};

void AttachDetours()
{
	// Call the attach() method on any detours you want to add
	// For example: cViewer_SetRenderType_detour::attach(GetAddress(cViewer, SetRenderType));

	UpdateAndGetColor__detour::attach(GetAddress(Simulator::cEmpire, UpdateAndGetColor));

}
// Generally, you don't need to touch any code here
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		ModAPI::AddPostInitFunction(Initialize);
		ModAPI::AddDisposeFunction(Dispose);

		PrepareDetours(hModule);
		AttachDetours();
		CommitDetours();
		break;

	case DLL_PROCESS_DETACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}

