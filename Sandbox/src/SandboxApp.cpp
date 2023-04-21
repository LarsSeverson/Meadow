#pragma once
#include <Meadow.h>
#include "Meadow/Core/EntryPoint.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <imgui/imgui.h>

class ExampleLayer : public Meadow::Layer
{
public:
	ExampleLayer() :
		Layer("Example"),
		vertexArray(std::make_shared<Meadow::VertexArray>())
	{

		// Vertex Buffer
		float positions[] = {
			-50.5f, -50.5f, 0.0f, 0.0f,
			 50.5f, -50.5f, 1.0f, 0.0f,
			 50.5f,  50.5f, 1.0f, 1.0f,
			-50.5f,  50.5f, 0.0f, 1.0f
		};
		std::shared_ptr<Meadow::VertexBuffer> vertexBuffer = std::make_shared<Meadow::VertexBuffer>(positions, (uint32_t)sizeof(positions));
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

		// Texture
		texture = std::make_shared<Meadow::Texture2D>("src/assets/textures/snoopy.png");
		texture->bind();
	}


	void onUpdate() override
	{
		{
			proj = glm::ortho(0.f, 1280.f, -0.f, 720.f, -1.f, 1.f);
			view = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, 0));
			model = glm::translate(glm::mat4(1.f), glm::vec3(100, 100, 0));
			mvp = proj * view * model;
			shader->uploadUniformMat4("uMVP", mvp);
			Meadow::Renderer::submit(shader, vertexArray);
		}
		{
			proj = glm::ortho(0.f, 1280.f, -0.f, 720.f, -1.f, 1.f);
			view = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, 0));
			model = glm::translate(glm::mat4(1.f), glm::vec3(400, 100, 0));
			mvp = proj * view * model;
			shader->uploadUniformMat4("uMVP", mvp);
			Meadow::Renderer::submit(shader, vertexArray);
		}
	}
	void onImGuiRender() override
	{
		//ImGui::Image((void*)texture->getRendererID(), ImVec2(400.f, 400.f));
	}

	void onEvent(Meadow::Event& event) override {

	}

private:
	std::shared_ptr<Meadow::VertexArray> vertexArray;
	std::shared_ptr<Meadow::Shader> shader;
	std::shared_ptr<Meadow::Texture2D> texture;

	glm::mat4 proj, view, model, mvp;
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
