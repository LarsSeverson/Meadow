#include "mdpch.h"
#include "Texture2D.h"

#include <stb_image.h>
#include <glad/glad.h>

namespace Meadow {
	Texture2D::Texture2D(const std::string& path)
		:
		path(path)
	{
		int width, height, channels;
		stbi_set_flip_vertically_on_load(1);
		stbi_uc* data = stbi_load(path.c_str(), &width, &height, &channels, 0);
		MD_CORE_ASSERT(data, "Failed to load image");
		this->width = width; this->height = height;

		// Loaded success
		GLenum internalFormat = 0, dataFormat = 0;
		if (channels == 4) { internalFormat = GL_RGBA8; dataFormat = GL_RGBA; }
		else if (channels == 3) { internalFormat = GL_RGB8; dataFormat = GL_RGB; }

		glCreateTextures(GL_TEXTURE_2D, 1, &rendererID);
		glTextureStorage2D(rendererID, 1, internalFormat, this->width, this->height);
		glTextureParameteri(rendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(rendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTextureSubImage2D(rendererID, 0, 0, 0, this->width, this->height, dataFormat, GL_UNSIGNED_BYTE, data);

		stbi_image_free(data);
	}
	Texture2D::~Texture2D()
	{
		glDeleteTextures(1, &rendererID);
	}
	void Texture2D::bind(uint32_t slot)
	{
		glBindTextureUnit(slot, rendererID);
	}
}