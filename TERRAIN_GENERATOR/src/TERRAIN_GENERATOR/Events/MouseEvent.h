#pragma once

#include "Event.h"

namespace TERRAIN_GENERATOR {

	class TERRAIN_GENERATOR_API MouseMovedEvent : public Event
	{
    public:
        MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}

        inline float GetX() const { return m_MouseX; }
        inline float GetY() const { return m_MouseY; }

        std::string ToString() const override 
        {
            std::stringstream ss;
            ss << "MouseMovedEvent to " << "(" << m_MouseX << ", " << m_MouseY << ")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:

        float m_MouseX;
        float m_MouseY;
	};

    class TERRAIN_GENERATOR_API MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(const float xOffset, const float yOffset)
            : m_XOffset(xOffset), m_YOffset(yOffset) {}

        float GetXOffset() const { return m_XOffset; }
        float GetYOffset() const { return m_YOffset; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
            EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:

        float m_XOffset;
        float m_YOffset;

    };

    class TERRAIN_GENERATOR_API MouseButtonEvent : public Event
    {
    public:
        inline int GetMouseButton() const { return m_Button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)

    protected:

        MouseButtonEvent(const int button) : m_Button(button) {}

        int m_Button;
    };

    class TERRAIN_GENERATOR_API MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(const int button) : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class TERRAIN_GENERATOR_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(const int button) : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}