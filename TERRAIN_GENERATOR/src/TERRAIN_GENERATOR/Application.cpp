#include "PCHeaders.h"
#include "Application.h"

#include "GLFW/glfw3.h"

namespace TERRAIN_GENERATOR
{
	Application::Application()
	{
		m_Window = std::unique_ptr<CWindow>(CWindow::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0, 1, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}

