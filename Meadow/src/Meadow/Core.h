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

#ifdef MD_ENABLE_ASSERTS
	#define MD_ASSERT(x, ...) { if (!(x)) {MD_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define MD_CORE_ASSERT(x, ...) { if (!(x)) {MD_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define MD_ASSERT(x, ...)
	#define MD_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)