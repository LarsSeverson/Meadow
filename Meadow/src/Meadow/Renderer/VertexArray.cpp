#include "mdpch.h"
#include "VertexArray.h"

#include <glad/glad.h>

namespace Meadow {

	static GLenum ShaderOpenGLType(ShaderDataType type) {
		switch (type)
		{
		case ShaderDataType::Float:	   return GL_FLOAT;
		case ShaderDataType::Float2:   return GL_FLOAT;
		case ShaderDataType::Float3:   return GL_FLOAT;
		case ShaderDataType::Float4:   return GL_FLOAT;
		case ShaderDataType::Mat3:     return GL_FLOAT;
		case ShaderDataType::Mat4:     return GL_FLOAT;
		case ShaderDataType::Int:      return GL_INT;
		case ShaderDataType::Int2:     return GL_INT;
		case ShaderDataType::Int3:     return GL_INT;
		case ShaderDataType::Int4:     return GL_INT;
		case ShaderDataType::Bool:     return GL_BOOL;
		}

		MD_CORE_ASSERT(false, "Unknown Shader data type.");
		return 0;
	}

	VertexArray::VertexArray()
	{
		glCreateVertexArrays(1, &rendererID);
	}
	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &rendererID);
	}
	void VertexArray::bind() const
	{
		glBindVertexArray(rendererID);
	}
	void VertexArray::unbind() const
	{
		glBindVertexArray(0);
	}
	void VertexArray::addVertexBuffer(const std::shared_ptr<VertexBuffer>& vb)
	{
		MD_CORE_ASSERT(vb->getLayout().getElements().size() > 0, "Vertex buffer has no layout.");

		glBindVertexArray(rendererID);
		vb->bind();

		uint32_t index = 0;
		const auto& layout = vb->getLayout();
		for (const auto& element : layout) {
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(
				index,
				element.getComponentCount(),
				ShaderOpenGLType(element.type),
				element.normalized ? GL_TRUE : GL_FALSE,
				layout.getStride(),
				(const void*)element.offset);
			index++;
		}
		vertexBuffers.emplace_back(vb);
	}
	void VertexArray::setIndexBuffer(const std::shared_ptr<IndexBuffer>& ib)
	{
		glBindVertexArray(rendererID);
		ib->bind();
		indexBuffer = ib;
	}
}