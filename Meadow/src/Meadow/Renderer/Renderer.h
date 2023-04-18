#pragma once

#include "Shader.h"
#include "VertexArray.h"

namespace Meadow {
	class Renderer
	{
	public:
		static void submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray);
	
	private:

	};
}

