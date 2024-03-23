#pragma once

#ifdef TG_PLATFORM_WINDOWS
	#ifdef TG_BUILD_DLL
		#define TERRAIN_GENERATOR_API __declspec(dllexport)
	#else
		#define TERRAIN_GENERATOR_API __declspec(dllimport)
	#endif
#else
	#error Windows-Only
#endif