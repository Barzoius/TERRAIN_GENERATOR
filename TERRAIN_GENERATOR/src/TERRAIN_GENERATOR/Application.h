#pragma once

#include "Core.h"

#include "Window.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"


namespace TERRAIN_GENERATOR {

    class TERRAIN_GENERATOR_API Application
    {
    public:
        Application();

        virtual ~Application();

        void Run();

        void OnEvent(Event& event);

        inline CWindow& GetWindow() { return *m_Window; }

    private:
        bool OnWindowClose(WindowCloseEvent& event);

        std::unique_ptr<CWindow> m_Window;
        bool m_Running = true;

    };

    Application* CreateApplication();
}