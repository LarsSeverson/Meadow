#pragma once
#include "mdpch.h"
#include "Meadow/Core.h"

namespace Meadow {

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved, 
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

//-------------------------------------------MACROS-------------------------------------------------------
	// These macros define the functions declared in Event
	// It's important to note these macros are not called when Event.h is compiled.
	// They are called in the child classes of class Event, and the pure virtual functions:
	// getStaticType(), getEventType(), getName(), and getCategoryFlags() are defined at call time.
#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::##type;}\
							   virtual EventType getEventType() const override {return getStaticType();}\
							   virtual const char* getName()    const override {return #type;}

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override {return category;}
//-------------------------------------------MACROS-------------------------------------------------------
	class MEADOW_API Event 
	{
		friend class EventDispatcher;
	public:
		virtual EventType getEventType() const = 0;
		virtual const char* getName()	 const = 0; // char* is necessary for toString()
		virtual int getCategoryFlags()	 const = 0;
		virtual std::string toString()	 const { return getName(); }

		inline bool isInCategory(EventCategory category) {
			// bit
			return getCategoryFlags() & category;
		}
	protected:
		bool mHandled = false;

	};
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) : mEvent(event) {}

		template<typename T>
		bool dispatch(EventFn<T> func) {
			if (mEvent.getEventType() == T::getStaticType()) {
				mEvent.mHandled = func(static_cast<T&>(mEvent));
				return true;
			}
			return false;
		}
	private:
		Event& mEvent;
	};
	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		// "e" for whichever polymorphed event it is (defined in each class)
		return os << e.toString();
	}
}