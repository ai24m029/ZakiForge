#include <ZakiForge.h>

class Sandbox : public ZakiForge::Application {

public:
	Sandbox()
	{

	}

	~Sandbox()
	{
	}
};

ZakiForge::Application* ZakiForge::CreateApplication() 
{
	return new Sandbox();
}