#pragma once

#include "Core.h"
#include "Window.h"

namespace TERRAIN_GENERATOR {

    class TERRAIN_GENERATOR_API Application
	{
	public:
		Application();

		virtual ~Application();

        void Run();

	private:
		std::unique_ptr<CWindow> m_Window;
		bool m_Running = true;
	};

    Application* CreateApplication();
}