#pragma once

#ifdef MD_PLATFORM_WINDOWS
	#ifdef MD_BUILD_DLL
		#define MEADOW_API _declspec(dllexport)
	#else 
		#define MEADOW_API _declspec(dllimport)
	#endif
#else 
	#error Meadow is only for Windows.
#endif

#define BIT(x) (1 << x)