#pragma once
#include "Event.h"
#include <sstream>

namespace Alpha {
	class ALPHA_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			:m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_MouseX, m_MouseY;
	};

	class ALPHA_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffSet, float yOffSet)
			:m_XOffset(xOffSet), m_YOffset(xOffSet) {}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;

	};

	class ALPHA_API MouseButtonEvent: public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button)
			:m_Button(button) {}

		int m_Button;
	};


	class ALPHA_API MouseButtonPressed : public MouseButtonEvent
	{
	public:
		MouseButtonPressed(int button)
			:MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressed: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)

	};


	class ALPHA_API MouseButtonReleased : public MouseButtonEvent
	{
	public:
		MouseButtonReleased(int button)
			:MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleased: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)

	};

	
}