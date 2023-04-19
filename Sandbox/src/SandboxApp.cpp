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

		// Vertex Buffer
		float positions[] = {
			-0.5f,  -0.5f,  0.0f,  0.0f,
			 0.5f,  -0.5f,  1.0f,  0.0f,
			 0.5f,   0.5f,  1.0f,  1.0f,
			-0.5f,   0.5f,  0.0f,  1.0f
		};
		std::shared_ptr<Meadow::VertexBuffer> vertexBuffer = std::make_shared<Meadow::VertexBuffer>(positions, sizeof(positions));
		vertexBuffer->setLayout({
			{ Meadow::ShaderDataType::Float2, "position" },
			{ Meadow::ShaderDataType::Float2, "texCoord" }
		});
		vertexArray->addVertexBuffer(vertexBuffer);

		// Index Buffer
		uint32_t indices[] = {
			0, 1, 2,
			2, 3, 0
		};
		std::shared_ptr<Meadow::IndexBuffer> indexBuffer = std::make_shared<Meadow::IndexBuffer>(indices, (uint32_t)6);
		vertexArray->setIndexBuffer(indexBuffer);

		// Shader
		shader = std::make_shared<Meadow::Shader>("src/assets/shaders/BasicTexture.shader");
		shader->uploadUniformInt("uTexture", 0);

		// Texture
		texture = std::make_shared<Meadow::Texture2D>("src/assets/textures/snoopy.png");
		texture->bind();
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
	std::shared_ptr<Meadow::Texture2D> texture;
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
