#pragma once

#ifdef MD_PLATFORM_WINDOWS
#else 
	#error Meadow is only for Windows.
#endif

#define MD_ASSERT(x, ...) { if (!(x)) {MD_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#define MD_CORE_ASSERT(x, ...) { if (!(x)) {MD_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}


#define BIT(x) (1 << x)