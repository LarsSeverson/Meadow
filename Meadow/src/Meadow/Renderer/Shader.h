#pragma once

namespace Meadow {
	enum class ShaderType {
		None = -1,
		Vertex,
		Fragment
	};

	class Shader
	{
	public:
		Shader(const std::string&& fileName);
		Shader(std::string& vertexSource, std::string& fragmentSource);
		~Shader();

		void bind() const;
		void unbind() const;

	private:
		struct ShaderSource { std::string vertexSource, fragmentSource; };
		ShaderSource source;
		uint32_t rendererID;
	};
}

