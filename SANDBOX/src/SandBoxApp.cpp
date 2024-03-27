#include <TERRAIN_GENERATOR.h>
#include <TERRAIN_GENERATOR/EntryPoint.h>

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