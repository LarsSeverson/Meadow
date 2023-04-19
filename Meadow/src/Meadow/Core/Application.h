#pragma once

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"
#include "Meadow/Events/Event.h"
#include "Meadow/Events/ApplicationEvent.h"

#include "Meadow/Renderer/Renderer.h"

namespace Meadow {

	class Application
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
