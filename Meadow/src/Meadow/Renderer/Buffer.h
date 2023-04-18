#pragma once

#include "BufferData.h"

namespace Meadow {
	class VertexBuffer 
	{
	public:
		VertexBuffer(const void* vertices, uint32_t size);
		~VertexBuffer();

		void bind()	  const;
		void unbind() const;

		BufferLayout getLayout() const { return bufferLayout; }
		void setLayout(const BufferLayout& layout) { bufferLayout = layout; }

	private:
		uint32_t rendererID;
		BufferLayout bufferLayout;
	};

	class IndexBuffer 
	{
	public:
		IndexBuffer(const void* indices, uint32_t count);
		~IndexBuffer();

		void bind()	  const;
		void unbind() const;

		inline uint32_t getCount() const { return count; }

	private:
		uint32_t rendererID;
		uint32_t count;
	};
}

