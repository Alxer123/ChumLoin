#include "plugin.h"
#include "mm/imgui/imgui.h"
#include <mm/game/go/character.h>
#include "mm/game/go/vehicle.h"
#include "mm/game/cameramanager.h"
#include "mm/core/input.h"

DLLATTATCH;

void PluginAttach(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
}


bool rightShiftPressed = false;
bool enabledAirBrake = false;
float speedBrake = 20.0;
DEFHOOK(void, CPlayer__UpdateController, (void* thiz, float dt)) {
	if (GetAsyncKeyState(VK_F1))
    {
        NEvent::CSendEvent<>::SendMsg("upg.companion.deactivate.p1.l1");
        NEvent::CSendEvent<>::SendMsg("upg.companion.activate.p1.l0");
    }

    if (GetAsyncKeyState(VK_F2))
    {
        NEvent::CSendEvent<>::SendMsg("upg.companion.deactivate.p1.l0");
        NEvent::CSendEvent<>::SendMsg("upg.companion.activate.p1.l1");
    }

    if (GetAsyncKeyState(VK_F3))
    {
        NEvent::CSendEvent<>::SendMsg("upg.companion.deactivate.p1.l0");
        NEvent::CSendEvent<>::SendMsg("upg.companion.deactivate.p1.l1");
    }

    return CPlayer__UpdateController_orig(thiz, dt);
}

void PluginHooks() {
	//ImGuiRenderer::Install();

    HookMgr::Install(ADDRESS(0x1404C6670, 0x1420DEAC0), CPlayer__UpdateController_hook, CPlayer__UpdateController_orig);
}