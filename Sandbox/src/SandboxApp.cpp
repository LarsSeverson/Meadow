#pragma once

#include <Meadow.h>

class Sandbox : public Meadow::Application
{
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};
Meadow::Application* Meadow::CreateApplication() {
	return new Sandbox();
}
