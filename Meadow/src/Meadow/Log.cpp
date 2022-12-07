#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Meadow {
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	
	void Log::Init() 
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		// Defines the name of each log whether client side or core side
		// Example of output log: MEADOW: <msg>
		s_CoreLogger = spdlog::stdout_color_mt("MEADOW");
		s_CoreLogger->set_level(spdlog::level::trace);

		// Example of ouput log: APP: <msg>
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}