#pragma once

#ifdef TG_PLATFORM_WINDOWS

extern TERRAIN_GENERATOR::Application* TERRAIN_GENERATOR::CreateApplication();

int main(int argc, char** argv)
{
	auto app = TERRAIN_GENERATOR::CreateApplication();

	app->Run();

	delete app;
}

#endif