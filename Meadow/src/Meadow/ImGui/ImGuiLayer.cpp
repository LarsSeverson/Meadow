#include "mdpch.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include "GLFW/glfw3.h"


#include "Meadow/Application.h"

namespace Meadow {
	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::onAttach() 
	{
		
	}

	void ImGuiLayer::onDetach()
	{
	}

	void ImGuiLayer::onUpdate() 
	{

	}

	void ImGuiLayer::onEvent(Event& event)
	{
	}
}