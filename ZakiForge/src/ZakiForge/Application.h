#pragma once
#include "Core.h"
#include "Events/Event.h"

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


