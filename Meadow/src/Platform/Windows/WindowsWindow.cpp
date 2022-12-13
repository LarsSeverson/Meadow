#include "mdpch.h"
#include "WindowsWindow.h"

namespace Meadow {

	static bool GLFWInit = false;

	Window* Window::Create(const WindowProperties& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& props) {
		WindowsWindow::init(props);
	}

	WindowsWindow::~WindowsWindow() {
		WindowsWindow::shutDown();
	}

	void WindowsWindow::init(const WindowProperties& props) {
		mData.windowTitle = props.windowTitle;
		mData.windowHeight = props.windowHeight;
		mData.windowWidth = props.windowWidth;

		MD_CORE_INFO("Creating window {0} ({1}, {2})", props.windowTitle, props.windowWidth, props.windowHeight);

		if (!GLFWInit) {

			int success = glfwInit();
			MD_CORE_ASSERT(success, "Could not initalize GLFW!");

			GLFWInit = true;
		}

		// GLFW stuff
		theWindow = glfwCreateWindow((int)props.windowWidth, (int)props.windowHeight, mData.windowTitle.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(theWindow);
		glfwSetWindowUserPointer(theWindow, &mData);

		setVSync(true);
	}

	void WindowsWindow::shutDown() {
		glfwDestroyWindow(theWindow);
	}

	void WindowsWindow::onUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(theWindow);
	}

	void WindowsWindow::setVSync(bool enabled) {
		if (enabled) {
			glfwSwapInterval(1);
		}
		else {
			glfwSwapInterval(0);
		}
		mData.vSync = enabled;
	}
	
	bool WindowsWindow::isVSync() const {
		return mData.vSync;
	}
}
