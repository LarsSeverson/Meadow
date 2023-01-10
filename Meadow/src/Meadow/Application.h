#pragma once

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"
#include "Events/Event.h"
#include "Meadow/Events/ApplicationEvent.h"

namespace Meadow {

	class MEADOW_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void onEvent(Event& e);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* layer);

		inline Window& getWindow() { return *appWindow; }

		inline static Application& get() { return *sInstance; }
	private:
		bool onWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> appWindow;
		static Application* sInstance;

		LayerStack appLayerStack;

		bool isRunning = true;
	};

	Application* CreateApplication();
	// Defined in sandbox / client
}
