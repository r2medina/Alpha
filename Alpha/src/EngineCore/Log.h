#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Alpha {
	class ALPHA_API Log
	{
	public:
		static void Init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


//Core log macros
#define LOG_CORE_TRACE(...) ::Alpha::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_CORE_INFO(...)  ::Alpha::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...)  ::Alpha::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...) ::Alpha::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CORE_FATAL(...) ::Alpha::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Core log macros
#define LOG_TRACE(...) ::Alpha::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)  ::Alpha::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)  ::Alpha::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) ::Alpha::Log::GetClientLogger()->error(__VA_ARGS__)
#define LOG_FATAL(...) ::Alpha::Log::GetClientLogger()->fatal(__VA_ARGS__)

