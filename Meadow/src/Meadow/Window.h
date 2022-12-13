#pragma once

#include "mdpch.h"

#include "Meadow/Core.h"
#include "Meadow/Events/Event.h"

namespace Meadow {
	struct WindowProperties {
		std::string windowTitle;
		unsigned int windowHeight;
		unsigned int windowWidth;
		WindowProperties(const std::string windowTitle = "Meadow Engine",
			unsigned int width = 1280, unsigned int height = 720) 
			: windowTitle(windowTitle), windowHeight(height), windowWidth(width) {}
	};

	// Abstract class / interface
	class MEADOW_API Window {
	public:
		using EventCallBackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void onUpdate() = 0;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		// Window attributes
		virtual void setEventCallBack(const EventCallBackFn& theEvent) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;
									// defined here / Create() call would work
		static Window* Create(const WindowProperties& props = WindowProperties());
	};
}