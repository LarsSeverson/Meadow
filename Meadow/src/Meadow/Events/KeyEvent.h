#pragma once

#include "Event.h"

namespace Meadow {
	class 
		
		KeyEvent : public Event
	{
	public:
		inline int getKeyCode() const { return mKeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(int keyCode) : mKeyCode(keyCode) {}
		int mKeyCode;
	};

	class  KeyPressedEvent : public KeyEvent
	{
	public :
		KeyPressedEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), mReapeatCount(repeatCount) {}

		inline int getRepeatCount() const { return mReapeatCount; }

		std::string toString() const override {
			// cout
			std::stringstream ss;

			ss << "KeyPressedEvent: " << mKeyCode << " (" << mReapeatCount << " repeats)";
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int mReapeatCount;
	};

	class  KeyReleasedEvent : public KeyEvent
	{
	public :
		KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}

		std::string toString() const override {
			std::stringstream ss;

			ss << "KeyReleasedEvent: " << mKeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}