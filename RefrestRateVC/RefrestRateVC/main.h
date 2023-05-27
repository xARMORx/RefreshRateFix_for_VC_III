#ifndef _MAIN_H_
#define _MAIN_H_

#include <Windows.h>
#include <memory>
#include "memwrapper/memwrapper.h"

using RwD3D8EngineSetRefreshRatePrototype = int(__cdecl*)(int);
std::unique_ptr<memwrapper::memhook<RwD3D8EngineSetRefreshRatePrototype>> RwD3D8EngineSetRefreshRateHook;

class AsiPlugin{
public:
	explicit AsiPlugin();
	virtual ~AsiPlugin();
} AsiPlugin;

#endif // !_MAIN_H_