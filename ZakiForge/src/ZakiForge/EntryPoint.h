#pragma once

#ifdef ZF_PLATFORM_WINDOWS

extern ZakiForge::Application* ZakiForge::CreateApplication();

int main(int argc, char** argv) 
{

	ZakiForge::Log::Init();
	ZF_CORE_WARN("Init Log!");
	ZF_INFO("Hello");

	auto app = ZakiForge::CreateApplication();
	app->Run();
	delete app;

	return 0;
}
  
#endif  