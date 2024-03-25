#include "PCHeaders.h"
#include "WindowsWindow.h"


namespace TERRAIN_GENERATOR
{

	static bool s_GLFWInitialized = false;

	CWindow* CWindow::Create(const SWindow_Specifics& specs)
	{
		return new WindowsWindow(specs);
	}

	WindowsWindow::WindowsWindow(const SWindow_Specifics& specs)
	{
		Init(specs);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const SWindow_Specifics& specs)
	{
		m_Data.Title = specs.m_Title;
		m_Data.Width = specs.m_Width;
		m_Data.Height = specs.m_Height;

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			
			//TG_CORE_ASSERT(success, "sds");

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(specs.m_Width, specs.m_Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}


	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);

	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);


		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}
