#include <TERRAIN_GENERATOR.h>

class SANDBOX : public TERRAIN_GENERATOR::Application
{
public:
		
	SANDBOX()
	{

	}

	~SANDBOX()
	{

	}

};

TERRAIN_GENERATOR::Application* TERRAIN_GENERATOR::CreateApplication()
{
	return new SANDBOX();
}