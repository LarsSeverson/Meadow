#pragma once

#include <Meadow.h>
#include "Meadow/Core/EntryPoint.h"

class ExampleLayer : public Meadow::Layer
{
public:
	ExampleLayer() : Layer("Example") {

		float positions[] = {
			-0.5f,  -0.5f,
			 0.5f,  -0.5f,
			 0.5f,   0.5f,
			-0.5f,   0.5f
		};
		vertexBuffer = std::make_shared<Meadow::VertexBuffer>(positions, 4 * 2 * sizeof(float));
		
		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};
		indexBuffer = std::make_shared<Meadow::IndexBuffer>(indices, 6 * sizeof(int));

		shader = std::make_shared<Meadow::Shader>("assets/shaders/Basic.shader");
	}

	void onUpdate() override
	{

	}

	void onEvent(Meadow::Event& event) override {

	}
private:
	std::shared_ptr<Meadow::Shader> shader;
	std::shared_ptr<Meadow::VertexBuffer> vertexBuffer;
	std::shared_ptr<Meadow::IndexBuffer> indexBuffer;
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
