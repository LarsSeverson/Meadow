#include "mdpch.h"
#include "Application.h"

#include "Meadow/Events/ApplicationEvent.h"
#include "Meadow/Log.h"

#include <GLFW/glfw3.h>

namespace Meadow {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() {
		appWindow = std::unique_ptr<Window>(Window::Create());

		// Setting WindowsWindow EventCallback = the function onEvent
		appWindow->setEventCallback(BIND_EVENT_FN(onEvent));
	}

	Application::~Application() {

	}

	// Every time there is an Event this function is called 
	void Application::onEvent(Event& e) {

		// (EventDispatcher::mEvent = e)
		EventDispatcher dispatcher(e);

		// dispatch(func = onWindowClose, T = WindowCloseEvent) -> takes in the function and also the functions type
		dispatcher.dispatch<WindowCloseEvent>([this](WindowCloseEvent& event) -> bool { return onWindowClose(std::forward<decltype(event)>(event)); });

		MD_CORE_TRACE("{0}", e);
	}

	bool Application::onWindowClose(WindowCloseEvent& e) {
		isRunning = false;
		return true;
	}

	void Application::Run() {
		while (isRunning) {
			glClearColor(1, 1, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			appWindow->onUpdate();
		}
	}
}