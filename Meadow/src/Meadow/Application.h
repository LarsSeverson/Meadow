#pragma once

#include "Core.h"
#include "Meadow/Events/ApplicationEvent.h"
#include "Meadow/Events/KeyEvent.h"

namespace Meadow {
	class MEADOW_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	Application* CreateApplication();
	// Defined in sandbox / client
}
