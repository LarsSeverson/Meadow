#pragma once

#include <Meadow.h>

class ExampleLayer : public Meadow::Layer
{
public:
	ExampleLayer(const std::string& d) : Layer("Example"), hey(d) {}

	void onUpdate() override
	{
		MD_INFO("ExampleLayer::Update");
	}

	void onEvent(Meadow::Event& event) override {
		MD_TRACE("{0}", event);
	}
private:
	std::string hey;
};

class Sandbox : public Meadow::Application
{
public:
	Sandbox() {
		pushLayer(new ExampleLayer("gey"));
		pushOverlay(new Meadow::ImGuiLayer());
	}
	~Sandbox() {

	}
};

Meadow::Application* Meadow::CreateApplication() {
	return new Sandbox();
}
