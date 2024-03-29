#pragma once

#include <glm/glm.hpp>

namespace Meadow {
	enum class ShaderType {
		None = -1,
		Vertex,
		Fragment
	};

	class Shader
	{
	public:
		Shader(const std::string& fileName);
		Shader(std::string& vertexSource, std::string& fragmentSource);
		~Shader();

		void bind() const;
		void unbind() const;

		void uploadUniformInt(const std::string& name, int value);

		void uploadUniformFloat4(const std::string& name, float x, float y, float z, float w);

		void uploadUniformMat4(const std::string& name, glm::mat4 matrix);

	private:
		struct ShaderSource { std::string vertexSource, fragmentSource; };
		ShaderSource source;
		uint32_t rendererID;
	};
}

