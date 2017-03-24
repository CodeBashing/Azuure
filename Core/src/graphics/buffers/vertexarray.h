#pragma once

//GLEW
#include <GL\glew.h>

//SDL
#include <vector>

//CUSTOM
#include "buffer.h"

namespace azuure { namespace graphics {
	class VertexArray {
	public:
		VertexArray();
		~VertexArray();

		void AddBuffer(Buffer *buffer, GLuint index);
		void Bind() const;
		void Unbind() const;
	private:
		GLuint m_arrayID;
		std::vector<Buffer*> m_buffers;
	};
}}