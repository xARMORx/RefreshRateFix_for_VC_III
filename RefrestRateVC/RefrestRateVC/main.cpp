#include "main.h"
HDC hDCScreen = GetDC(NULL);

int RwD3D8EngineSetRefreshRate(int rate) {
	rate = GetDeviceCaps(hDCScreen, VREFRESH);
	return RwD3D8EngineSetRefreshRateHook->call<int>(rate);
}

AsiPlugin::AsiPlugin() {
	RwD3D8EngineSetRefreshRateHook = std::make_unique<memwrapper::memhook<RwD3D8EngineSetRefreshRatePrototype>>(0x65DBC0, &RwD3D8EngineSetRefreshRate);
	RwD3D8EngineSetRefreshRateHook->install();
}

AsiPlugin::~AsiPlugin() {
	RwD3D8EngineSetRefreshRateHook->remove();
}