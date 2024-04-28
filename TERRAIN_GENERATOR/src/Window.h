#pragma once

#include "PCHeaders.h"

#include "TERRAIN_GENERATOR/Core.h"
#include "TERRAIN_GENERATOR/Events/Event.h"


namespace TERRAIN_GENERATOR
{

    struct SWindow_Specifics
    {
        std::string m_Title;
        uint32_t m_Width;
        uint32_t  m_Height;

        SWindow_Specifics(const std::string& title = "TERRAIN_GENERATOR",
                          uint32_t  W = 1280, uint32_t  H = 720)
                          :
                          m_Title(title), m_Width(W), m_Height(H) {}

    };


    //-----------------------(CWindow)-----------------------//
    //Name:                   CWindow                         |
    //Description:            An Interface for OS based       |
    //                        window implementations.         |
    //-------------------------------------------------------//
    class TERRAIN_GENERATOR_API CWindow
    {
    public:


        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~CWindow() = default;

        virtual void OnUpdate() = 0;

        virtual uint32_t  GetWidth() const = 0;
        virtual uint32_t  GetHeight() const = 0;


        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;


        static CWindow* Create(const SWindow_Specifics& specs = SWindow_Specifics());

    };
}