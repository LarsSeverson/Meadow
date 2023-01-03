#include "mdpch.h"
#include "WindowsWindow.h"

#include "Meadow/Events/ApplicationEvent.h"
#include "Meadow/Events/KeyEvent.h"
#include "Meadow/Events/MouseEvent.h"

#include <glad/glad.h>

namespace Meadow {

	static bool GLFWInit = false;

	static void GLFWErrorCallback(int error, const char* description) {
		MD_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

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
			MD_CORE_ASSERT(success, "Could not initialize GLFW!");

			GLFWInit = true;
		}

		// GLFW stuff
		glfwWindow = glfwCreateWindow((int)props.windowWidth, (int)props.windowHeight, mData.windowTitle.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(glfwWindow);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MD_CORE_ASSERT(status, "Failed to initialize Glad!");
		glfwSetWindowUserPointer(glfwWindow, &mData);

		setVSync(true);

		// Callback to GLFW functions (events)
		// Set Window Size
		glfwSetWindowSizeCallback(glfwWindow, [](GLFWwindow* window, int width, int height) {

			// Need to access EventCallBack function in WindowData -> reference variable with cast
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.windowWidth = width;
			data.windowHeight = height;

			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		});

		// Close Window
		glfwSetWindowCloseCallback(glfwWindow, [](GLFWwindow* window) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowCloseEvent event;

			// See setEventCallback() in WindowsWindow.h
			data.EventCallback(event);
		});

		// Key Event
		glfwSetKeyCallback(glfwWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action) {
			case GLFW_PRESS: {
				KeyPressedEvent event(key,0);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE: {
				KeyReleasedEvent event(key);
				data.EventCallback(event);
				break;
			}
			case GLFW_REPEAT: {
				KeyPressedEvent event(key, 1);
				data.EventCallback(event);
				break;
			}
			}
		});

		// Mouse Event
		glfwSetMouseButtonCallback(glfwWindow, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			switch (action) {
			case GLFW_PRESS: {
				MouseButtonPressedEvent event(button);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE: {
				MouseButtonReleasedEvent event(button);
				data.EventCallback(event);
				break;
			}
			}
		});

		// Mouse Scroll Event
		glfwSetScrollCallback(glfwWindow, [](GLFWwindow* window, double xOff, double yOff) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			MouseScrolledEvent event((float)xOff, (float)yOff);
			data.EventCallback(event);
		});

		// Mouse Cursor Event
		glfwSetCursorPosCallback(glfwWindow, [](GLFWwindow* window, double xPos, double yPos) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			MouseMovedEvent event((float)xPos, (float)yPos);
			data.EventCallback(event);
		});
	}

	void WindowsWindow::shutDown() {
		glfwDestroyWindow(glfwWindow);
	}

	void WindowsWindow::onUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(glfwWindow);
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
