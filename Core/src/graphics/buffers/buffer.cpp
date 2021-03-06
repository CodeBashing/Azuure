#include "buffer.h"

namespace azuure { namespace graphics {
	/*Constructor and Destructor*/
	Buffer::Buffer(GLfloat * data, GLsizei count, GLuint componentCount)
		:m_componentCount(componentCount)
	{
		glGenBuffers(1, &m_bufferID);
		glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	/*Public Methodes*/
	void Buffer::Bind(){
		glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
	}
	void Buffer::Unbind(){
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}}