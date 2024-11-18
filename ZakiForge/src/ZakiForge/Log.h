#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

#include <memory>
namespace ZakiForge
{
	class ZAKIFORGE_API Log
	{
	public: 
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};


}

//Core log macros
#define ZF_CORE_ERROR(...) ::ZakiForge::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ZF_CORE_WARN(...)  ::ZakiForge::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ZF_CORE_INFO(...)  ::ZakiForge::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ZF_CORE_TRACE(...) ::ZakiForge::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ZF_CORE_FATAL(...) ::ZakiForge::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client log macros
#define ZF_ERROR(...) ::ZakiForge::Log::GetClientLogger()->error(__VA_ARGS__)
#define ZF_WARN(...)  ::ZakiForge::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ZF_INFO(...)  ::ZakiForge::Log::GetClientLogger()->info(__VA_ARGS__)
#define ZF_TRACE(...) ::ZakiForge::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ZF_FATAL(...) ::ZakiForge::Log::GetClientLogger()->critical(__VA_ARGS__)