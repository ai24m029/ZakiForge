#include "Application.h"
#include "ZakiForge/Events/ApplicationEvent.h"
#include "ZakiForge/Log.h"

namespace ZakiForge {

	Application::Application() 
	{

	}

	Application::~Application() 
	{

	}

	void Application::Run() 
	{
		WindowResizeEvent e(1280, 720);

		if (e.IsInCategory(EventCategoryApplication))
		{
			ZF_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			ZF_TRACE(e.ToString());
		}
		while (true);
	}
}