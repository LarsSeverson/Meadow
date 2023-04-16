#include "mdpch.h"
#include "Buffer.h"

#include <glad/glad.h>


namespace Meadow {
	VertexBuffer::VertexBuffer(const void* vertices, uint32_t size)
	{
		glGenBuffers(1, &rendererID);
		glBindBuffer(GL_ARRAY_BUFFER, rendererID);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}
	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &rendererID);
	}
	void VertexBuffer::bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, rendererID);
	}
	void VertexBuffer::unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	//----------------------------------------------------------------------------------
	IndexBuffer::IndexBuffer(const void* indices, uint32_t size)
	{
		glGenBuffers(1, &rendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);

	}
	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &rendererID);
	}
	void IndexBuffer::bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID);
	}
	void IndexBuffer::unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}