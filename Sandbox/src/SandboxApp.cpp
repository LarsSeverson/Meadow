#pragma once

#include <Meadow.h>

class ExampleLayer : public Meadow::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void onUpdate() override
	{
		MD_INFO("ExampleLayer::Update");
	}

	void onEvent(Meadow::Event& event) override {
		MD_TRACE("{0}", event);
	}
};

class Sandbox : public Meadow::Application
{
public:
	Sandbox() {
		pushLayer(new ExampleLayer()); 
		pushOverlay(new Meadow::ImGuiLayer());
	}
	~Sandbox() {

	}
};

Meadow::Application* Meadow::CreateApplication() {
	return new Sandbox();
}
