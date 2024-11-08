#pragma once

#ifdef ZF_PLATFORM_WINDOWS

extern ZakiForge::Application* ZakiForge::CreateApplication();

int main(int argc, char** argv) {

	printf("Zaki ENgine");
	auto app = ZakiForge::CreateApplication();
	app->Run();
	delete app;

	return 0;
}
  
#endif