#pragma once

#include "Buffer.h"

namespace Meadow {
	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();

		void bind() const;
		void unbind() const;

		void addVertexBuffer(const std::shared_ptr<VertexBuffer>& vb);
		void setIndexBuffer(const std::shared_ptr<IndexBuffer>& ib);

		const std::shared_ptr<IndexBuffer>& getIndexBuffer() const { return indexBuffer; }

	private:
		uint32_t rendererID;
		std::vector<std::shared_ptr<VertexBuffer>> vertexBuffers;
		std::shared_ptr<IndexBuffer> indexBuffer;
	};
}

