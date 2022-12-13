#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Meadow {
	class MEADOW_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> theWindow;
		bool isRunning = true;
	};
	Application* CreateApplication();
	// Defined in sandbox / client
}
