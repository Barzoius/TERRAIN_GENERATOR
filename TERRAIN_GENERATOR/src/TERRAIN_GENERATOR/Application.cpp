#include "PCHeaders.h"
#include "Application.h"

#include "GLFW/glfw3.h"

namespace TERRAIN_GENERATOR
{

//#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application()
    {
        m_Window = std::unique_ptr<CWindow>(CWindow::Create());
        //m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }

    Application::~Application()
    {

    }

    /*void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer* overlay)
    {
        m_LayerStack.PushOverlay(overlay);
    }*/

    //void Application::OnEvent(Event& event)
    //{
    //	
    //	EventDispatcher dispatcher(event);
    //	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

    //	/*for(auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
    //	{ 
    //		(*--it)->OnEvent(event);

    //		if (event.Handled)
    //			break;
    //	}*/
    //}

    void Application::Run()
    {
        while (m_Running)
        {
            glClearColor(0, 1, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);

            /*for (Layer* layer : m_LayerStack)
                layer->OnUpdate();*/

            m_Window->OnUpdate();
        }
    }


    bool Application::OnWindowClose(WindowCloseEvent& event)
    {
        m_Running = false;
        return true;
    }
}

