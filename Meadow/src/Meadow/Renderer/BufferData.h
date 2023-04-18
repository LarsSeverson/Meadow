#pragma once

namespace Meadow {

	enum class ShaderDataType {
		None = 0,
		Float, Float2, Float3, Float4,
		Mat3, Mat4,
		Int, Int2, Int3, Int4,
		Bool
	};

	static uint32_t ShaderDataTypeSize(ShaderDataType type) {
		
		switch (type)
		{
		case ShaderDataType::Float:		return 4;
		case ShaderDataType::Float2:	return 4 * 2;
		case ShaderDataType::Float3:	return 4 * 3;
		case ShaderDataType::Float4:	return 4 * 4;
		case ShaderDataType::Mat3:		return 4 * 3 * 3;
		case ShaderDataType::Mat4:		return 4 * 4 * 4;
		case ShaderDataType::Int:		return 4;
		case ShaderDataType::Int2:		return 4 * 2;
		case ShaderDataType::Int3:		return 4 * 3;
		case ShaderDataType::Int4:		return 4 * 4;
		case ShaderDataType::Bool:		return 1;
		}

		MD_CORE_ASSERT(false, "Unknown ShaderDataType.");
		return 0;
	}

	struct BufferElement
	{
		BufferElement() = default;
		BufferElement(ShaderDataType type, const std::string& name, bool normalized = false) 
			: 
			name(name),
			type(type),
			normalized(normalized),
			size(ShaderDataTypeSize(type)),
			offset(0)
		{}

		uint32_t getComponentCount() const { 
			return size == 1 ? 1 : size / 4; 
		}

		std::string name;
		ShaderDataType type;
		bool normalized;
		uint32_t size;
		uint32_t offset;
	};

	class BufferLayout
	{
	public:
		BufferLayout() = default;
		BufferLayout(const std::initializer_list<BufferElement>& elements)
			:
			elements(elements),
			stride(0)
		{
			uint32_t offset = 0;
			for (auto& element : this->elements) {
				element.offset = offset;
				offset += element.size;
				stride += element.size;
			}
		}

		inline uint32_t getStride() const { return stride; }
		inline const std::vector<BufferElement>& getElements() const { return elements; }

		std::vector<BufferElement>::iterator begin() { return elements.begin(); }
		std::vector<BufferElement>::iterator end() { return elements.end(); }
		std::vector<BufferElement>::const_iterator begin() const { return elements.begin(); }
		std::vector<BufferElement>::const_iterator end() const { return elements.end(); }

	private:
		std::vector<BufferElement> elements;
		uint32_t stride;
	};
}