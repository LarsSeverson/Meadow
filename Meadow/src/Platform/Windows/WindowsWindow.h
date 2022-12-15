#pragma once

#include "Meadow/Window.h"

#include <GLFW/glfw3.h>

namespace Meadow {

	class MEADOW_API WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties& props);
		virtual ~WindowsWindow();

		void onUpdate() override;

		inline unsigned int getWidth() const override { return mData.windowWidth; }
		inline unsigned int getHeight() const override { return mData.windowHeight; }
		
		inline void setEventCallBack(const EventCallBackFn& callback) override { mData.EventCallback = callback; }
		void setVSync(bool enabled) override;
		bool isVSync() const override;
	private:
		virtual void init(const WindowProperties& props);
		virtual void shutDown();

		GLFWwindow* glfwWindow;

		struct WindowData {
			std::string windowTitle;

			unsigned int windowWidth, windowHeight;
			bool vSync;

			EventCallBackFn EventCallback;
		};

		WindowData mData;
	};
}

