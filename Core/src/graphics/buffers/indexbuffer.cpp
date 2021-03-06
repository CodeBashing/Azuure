#include "indexbuffer.h"

namespace azuure { namespace graphics {
		/*Constructor and Destructor*/
		IndexBuffer::IndexBuffer(GLushort * data, GLsizei count)
			:m_count(count)
		{
			glGenBuffers(1, &m_bufferID);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

		/*Public Methodes*/
		void IndexBuffer::Bind() const{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID);
		}
		void IndexBuffer::Unbind() const{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
}}