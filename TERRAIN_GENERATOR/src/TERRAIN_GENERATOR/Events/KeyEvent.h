#pragma once

#include "Event.h"

namespace TERRAIN_GENERATOR {

    class TERRAIN_GENERATOR_API KeyEvent : public Event
    {
    public:

        inline int GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:

        KeyEvent(int keycode) : m_KeyCode(keycode) {}
        int m_KeyCode;

    };

    class TERRAIN_GENERATOR_API KeyPressedEvent : public  KeyEvent
    {
    public:
        KeyPressedEvent(int keycode, int repeatCount)
            : KeyEvent(keycode), m_RepeatCount(repeatCount) {}

        inline int GetRepeatCount() const { return m_RepeatCount; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << ",repeats: " << m_RepeatCount;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)

    private:
        int m_RepeatCount;

    };

    class TERRAIN_GENERATOR_API KeyReleasedEvent : public KeyEvent
    {
    public:
    public:
        KeyReleasedEvent(int keycode)
            : KeyEvent(keycode) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };

}