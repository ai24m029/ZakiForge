#pragma once
#include "Core.h"

namespace ZakiForge{
	class ZAKIFORGE_API Application
	{
	public: 
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}


