#include "mdpch.h"
#include "Application.h"

#include "Meadow/Events/ApplicationEvent.h"
#include "Meadow/Log.h"

#include <GLFW/glfw3.h>

namespace Meadow {
	Application::Application() {
		theWindow = std::unique_ptr<Window>(Window::Create());
	}
	Application::~Application() {

	}
	void Application::Run() {
		while (isRunning) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			theWindow->onUpdate();
		}
	}
}