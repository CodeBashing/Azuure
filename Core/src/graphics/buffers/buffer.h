#pragma once

//GLEW
#include <GL\glew.h>

namespace azuure { namespace graphics {
	class Buffer {
	public:
		Buffer(GLfloat *data, GLsizei count, GLuint componentCount);

		inline GLuint getComponentCount() const { return m_componentCount; }

		void Bind();
		void Unbind();
	private:
		GLuint m_bufferID;
		GLuint m_componentCount;
	};
}}