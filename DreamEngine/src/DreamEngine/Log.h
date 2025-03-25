#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"

#include "spdlog/fmt/ostr.h"

namespace DreamEngine {
	class DREAM_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core Log macros
#define DE_CORE_ERROR(...)  ::DreamEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DE_CORE_WARN(...)   ::DreamEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)	
#define DE_CORE_INFO(...)   ::DreamEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DE_CORE_TRACE(...)  ::DreamEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DE_CORE_FATAL(...)  ::DreamEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)


//Client Log macros
#define DE_ERROR(...)  ::DreamEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define DE_WARN(...)   ::DreamEngine::Log::GetClientLogger()->warn(__VA_ARGS__)	
#define DE_INFO(...)   ::DreamEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define DE_TRACE(...)  ::DreamEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DE_FATAL(...)  ::DreamEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)


