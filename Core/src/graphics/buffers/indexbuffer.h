#pragma once

//GLEW
#include <GL\glew.h>

namespace azuure { namespace graphics {
		class IndexBuffer {
		public:
			IndexBuffer(GLushort *data, GLsizei count);

			inline GLuint GetCount() const { return m_count; }

			void Bind() const;
			void Unbind() const;
		private:
			GLuint m_bufferID;
			GLuint m_count;
		};
}}