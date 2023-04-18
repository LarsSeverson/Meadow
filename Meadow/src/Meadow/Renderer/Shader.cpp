#include "mdpch.h"
#include "Shader.h"

#include <glad/glad.h>

namespace Meadow {
	Shader::Shader(const std::string&& fileName)
	{
        // Open file
        std::ifstream stream(fileName);
        MD_ASSERT(stream.is_open(), "Could not open file: ");
        std::string line;
        std::stringstream ss[2];
        ShaderType type = ShaderType::None;
        while (getline(stream, line)) {
            if (line.find("#shader") != std::string::npos) {
                if (line.find("vertex") != std::string::npos) {
                    type = ShaderType::Vertex;
                }
                else if (line.find("fragment") != std::string::npos) {
                    type = ShaderType::Fragment;
                }
            }
            else {
                ss[(int)type] << line << '\n';
            }
        }
       source = { ss[0].str(), ss[1].str() };
       // End file
       
       GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
       const GLchar* glSource = source.vertexSource.c_str();
       glShaderSource(vertexShader, 1, &glSource, 0);
       glCompileShader(vertexShader);

       // Check if GL OK - vertexSource
       GLint isCompiled = 0;
       glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
       if (isCompiled == GL_FALSE) {
           GLint maxLength = 0;
           glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

           std::vector<GLchar> infoLog(maxLength);
           glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

           glDeleteShader(vertexShader);

           MD_CORE_ERROR("{0}", infoLog.data());
           MD_CORE_ASSERT(false, "Vertex shader compilation failed.");
       }
       // End check

       GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
       glSource = source.fragmentSource.c_str();
       glShaderSource(fragmentShader, 1, &glSource, 0);
       glCompileShader(fragmentShader);
       
       // Check if GL OK - fragmentSource
       glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
       if (isCompiled == GL_FALSE) {
           GLint maxLength = 0;
           glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

           std::vector<GLchar> infoLog(maxLength);
           glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

           glDeleteShader(fragmentShader);
           glDeleteShader(vertexShader);

           MD_CORE_ERROR("{0}", infoLog.data());
           MD_CORE_ASSERT(0, "Failed to load fragment shader.");
       }
       // End check

       // Success...
       rendererID = glCreateProgram();
       GLuint program = rendererID;

       glAttachShader(program, vertexShader);
       glAttachShader(program, fragmentShader);
       glLinkProgram(program);

       // Check linkage
       GLint isLinked = 0;
       glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
       if (isLinked == GL_FALSE) {
           GLint maxLength = 0;
           glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

           std::vector<GLchar> infoLog(maxLength);
           glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

           glDeleteProgram(program);
           glDeleteShader(fragmentShader);
           glDeleteShader(vertexShader);

           MD_CORE_ERROR("{0}", infoLog.data());
           MD_CORE_ASSERT(0, "Failed to load fragment shader.");
       }
       // End check

       glDetachShader(program, vertexShader);
       glDetachShader(program, fragmentShader);

       this->bind();
    }

	Shader::Shader(std::string& vertexSource, std::string& fragmentSource)
	{
		
	}
    Shader::~Shader()
    {
        glDeleteProgram(rendererID);
    }
    void Shader::bind() const
    {
        glUseProgram(rendererID);
    }
    void Shader::unbind() const
    {
        glUseProgram(0);
    }
    void Shader::uploadUniformFloat4(const std::string& name, float x, float y, float z, float w)
    {
        GLint location = glGetUniformLocation(rendererID, name.c_str());
        glUniform4f(location, x, y, z, w);
    }
}