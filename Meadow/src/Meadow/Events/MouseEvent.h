#pragma once
#include "Event.h"

namespace Meadow {
	//-------------------------Mouse Moved-------------------------
	class 
		MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) : mMouseX(x), mMouseY(y) {}

		inline float getMouseX() { return mMouseX; }
		inline float getMouseY() { return mMouseY; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << mMouseX << " , " << mMouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float mMouseX, mMouseY;
	};
	//------------------------------------------------------------
	//----------------------Mouse Scrolled------------------------
	class  MouseScrolledEvent : public Event
	{
	public:

		MouseScrolledEvent(float x, float y) : mOffsetX(x), mOffsetY(y) {}

		inline float getOffsetX() const { return mOffsetX; }
		inline float getOffsetY() const { return mOffsetY; }

		std::string toString() const override {
			std::stringstream ss;
			
			ss << "MouseScrolledEvent: " << mOffsetX << " , " << mOffsetY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		// could just be y value of up and down - not sure if this will change
		float mOffsetX, mOffsetY;
	};
	//------------------------------------------------------------
	//--------------------Mouse Button Event----------------------
	class  MouseButtonEvent : public Event
	{
	public:
		inline int getMouseButton() { return mButton; }
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button) : mButton(button) {}
		int mButton;
	};
	//------------------------------------------------------------
	//--------------------Mouse Button Event----------------------
	// Pressed
	class  MouseButtonPressedEvent : public MouseButtonEvent
	{	
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << mButton;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};
	//------------------------------------------------------------
	//--------------------Mouse Button Event----------------------
	// Released
	class  MouseButtonReleasedEvent : public MouseButtonEvent
	{	
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << mButton;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}