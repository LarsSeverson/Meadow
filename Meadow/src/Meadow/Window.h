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
	class Window 
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void onUpdate() = 0;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		// Window attributes
			// Check bind in Application.cpp 
		virtual void setEventCallback(const EventCallbackFn& theEvent) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;
									// defined here / Create() call would work
		static Window* Create(const WindowProperties& props = WindowProperties());
	};
}