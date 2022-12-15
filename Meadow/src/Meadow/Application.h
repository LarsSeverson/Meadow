#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Meadow/Events/ApplicationEvent.h"

#include "Window.h"

namespace Meadow {
	class MEADOW_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void onEvent(Event& e);
	private:
		bool onWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> appWindow;
		bool isRunning = true;
	};

	Application* CreateApplication();
	// Defined in sandbox / client
}
