#include "PCHeaders.h"
#include "WindowsWindow.h"

#include "TERRAIN_GENERATOR/Events/ApplicationEvent.h"


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

        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
        {
                SWindow_Data& data = *(SWindow_Data*)glfwGetWindowUserPointer(window);

                WindowResizeEvent event(width, height);

                data.Width = width;
                data.Height = height;

                data.EventCallback(event);


        });


        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
        {
                SWindow_Data& data = *(SWindow_Data*)glfwGetWindowUserPointer(window);
                WindowCloseEvent event;

                data.EventCallback(event);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
            {
                SWindow_Data& data = *(SWindow_Data*)glfwGetWindowUserPointer(window);
                
                switch (action)
                {
                case GLFW_PRESS:
                {
                    //KeyPressedEvent event(key, 0)
                    break;
                }
                case GLFW_RELEASE:
                    break;
                case GLFW_REPEAT:
                    break;

                }

            });

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
