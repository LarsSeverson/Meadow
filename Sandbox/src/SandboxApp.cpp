#pragma once

#include <Meadow.h>
#include "Meadow/EntryPoint.h"

class ExampleLayer : public Meadow::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void onUpdate() override
	{

	}

	void onEvent(Meadow::Event& event) override {

	}
private:

};

class Sandbox : public Meadow::Application
{
public:
	Sandbox() {
		pushLayer(new ExampleLayer());
	}
	~Sandbox() {

	}
};

Meadow::Application* Meadow::CreateApplication() {
	return new Sandbox();
}
