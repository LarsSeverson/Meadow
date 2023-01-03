#include "mdpch.h"
#include "Application.h"

#include "Meadow/Events/ApplicationEvent.h"
#include "Meadow/Log.h"

#include <glad/glad.h>

namespace Meadow {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() {
		appWindow = std::unique_ptr<Window>(Window::Create());

		// Setting WindowsWindow EventCallback = the function onEvent
		appWindow->setEventCallback(BIND_EVENT_FN(onEvent));

		unsigned int id;
		glGenVertexArrays(1, &id);
	}

	Application::~Application() {

	}


	void Application::pushLayer(Layer* layer) {
		appLayerStack.pushLayer(layer);
	}

	void Application::pushOverlay(Layer* layer) {
		appLayerStack.pushOverlay(layer);
	}

	// Every time there is an Event this function is called 
	void Application::onEvent(Event& e) {

		// (EventDispatcher::mEvent = e)
		EventDispatcher dispatcher(e);
		// dispatch(func = onWindowClose, T = WindowCloseEvent) -> takes in the function and also the functions type
		dispatcher.dispatch<WindowCloseEvent>([this](WindowCloseEvent& event) -> bool { return onWindowClose(std::forward<decltype(event)>(event)); });

		// Will continuously look for events happening in the layer stack
		for (auto it = appLayerStack.end(); it != appLayerStack.begin();) {
			// Not the last layer in the stack -> increment down and check events
			(*--it)->onEvent(e); // Layer*->
			if (e.EventHandled) {
				break;
			}
		}
	}
	bool Application::onWindowClose(WindowCloseEvent& e) {
		isRunning = false;
		return true;
	}

	void Application::Run() {
		while (isRunning) {
			glClearColor(1, 1, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : appLayerStack) {
				layer->onUpdate();
			}

			appWindow->onUpdate();
		}
	}
}