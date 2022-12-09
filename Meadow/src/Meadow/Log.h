#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
// To make able to VA ARGS an object
#include "spdlog/fmt/ostr.h"

#include <memory>

namespace Meadow {
	class MEADOW_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;}
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
	// Macros for parameter packs (variadic templates) require (...) for macro parameters and 
	// (__VA_ARGS__) to pass the parameter into the function 
#define MD_CORE_TRACE(...)	::Meadow::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MD_CORE_INFO(...)	::Meadow::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MD_CORE_WARN(...)	::Meadow::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MD_CORE_ERROR(...)	::Meadow::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MD_CORE_FATAL(...)	::Meadow::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define MD_TRACE(...)		::Meadow::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MD_INFO(...)		::Meadow::Log::GetClientLogger()->info(__VA_ARGS__)
#define MD_WARN(...)		::Meadow::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MD_ERROR(...)		::Meadow::Log::GetClientLogger()->error(__VA_ARGS__)
#define MD_FATAL(...)		::Meadow::Log::GetClientLogger()->fatal(__VA_ARGS__)