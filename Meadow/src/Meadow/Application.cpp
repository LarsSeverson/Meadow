#include "Application.h"
#include "Log.h"
namespace Meadow {
	Application::Application() {

	}
	Application::~Application() {

	}
	void Application::Run() {
		WindowResizeEvent e(1200, 3);
		if (e.isInCategory(Meadow::EventCategoryApplication)) {
			MD_TRACE(e);
		}
		while (true) {

		}
	}
}