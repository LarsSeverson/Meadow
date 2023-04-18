#pragma once

#include <Meadow.h>
#include "Meadow/Core/EntryPoint.h"

class ExampleLayer : public Meadow::Layer
{
public:
	ExampleLayer() :
		Layer("Example"),
		vertexArray(std::make_shared<Meadow::VertexArray>())
	{

		float positions[] = {
			-0.5f,  -0.5f,
			 0.5f,  -0.5f,
			 0.5f,   0.5f,
			-0.5f,   0.5f
		};
		std::shared_ptr<Meadow::VertexBuffer> vertexBuffer = std::make_shared<Meadow::VertexBuffer>(positions, 4 * 2 * sizeof(float));
		vertexBuffer->setLayout({
			{ Meadow::ShaderDataType::Float2, "" }
		});
		vertexArray->addVertexBuffer(vertexBuffer);

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};
		std::shared_ptr<Meadow::IndexBuffer> indexBuffer = std::make_shared<Meadow::IndexBuffer>(indices, 6);
		vertexArray->setIndexBuffer(indexBuffer);

		shader = std::make_shared<Meadow::Shader>("src/assets/shaders/Basic.shader");
		shader->uploadUniformFloat4("uColor", 0.8f, 0.3f, 0.8f, 1.0f);
	}

	void onUpdate() override
	{
		Meadow::Renderer::submit(shader, vertexArray);
	}

	void onEvent(Meadow::Event& event) override {

	}
private:

	std::shared_ptr<Meadow::VertexArray> vertexArray;
	std::shared_ptr<Meadow::Shader> shader;
	
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
