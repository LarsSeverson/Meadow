#pragma once

namespace Meadow {
	class Texture2D
	{
	public:
		Texture2D(const std::string& path);
		~Texture2D();

		void bind(uint32_t slot = 0);

		uint32_t getWdith() const { return width; }
		uint32_t getHeight() const { return height; }
		uint32_t getRendererID() const { return rendererID; }

	private:
		std::string path;
		uint32_t width, height;
		uint32_t rendererID;
	};
}
