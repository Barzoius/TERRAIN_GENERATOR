#pragma once
#include "Core.h"

namespace TERRAIN_GENERATOR {

	class TERRAIN_GENERATOR_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

