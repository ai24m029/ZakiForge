#pragma once
#ifdef ZF_PLATFORM_WINDOWS
	#ifdef ZF_BUILD_DLL
		#define ZAKIFORGE_API __declspec(dllexport)
	#else
		#define ZAKIFORGE_API __declspec(dllimport)
	#endif
#else
	#error ZakiForge only supports Windows!
#endif

#define BIT(x) (1 << x)