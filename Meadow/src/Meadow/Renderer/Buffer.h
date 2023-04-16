#pragma once

#include "Renderer.h"

namespace Meadow {
	class VertexBuffer 
	{
	public:
		VertexBuffer(const void* vertices, uint32_t size);
		~VertexBuffer();

		void bind()	  const;
		void unbind() const;

	private:
		uint32_t rendererID;
	};

	class IndexBuffer 
	{
	public:
		IndexBuffer(const void* indices, uint32_t size);
		~IndexBuffer();

		void bind()	  const;
		void unbind() const;

	private:
		uint32_t rendererID;
	};
}

