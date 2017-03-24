#include "vertexarray.h"

namespace azuure { namespace graphics {
	/*Constructor and Destructor*/
	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &m_arrayID);
	}
	VertexArray::~VertexArray()
	{
		for (unsigned int i = 0; i < m_buffers.size(); i++)
			delete m_buffers[i];
	}

	/*Public Methodes*/
	void VertexArray::AddBuffer(Buffer * buffer, GLuint index){
		Bind();
		buffer->Bind();

		glEnableVertexArrayAttrib(m_arrayID, index);
		glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

		buffer->Unbind();
		Unbind();
	}
	void VertexArray::Bind() const{
		glBindVertexArray(m_arrayID);
	}
	void VertexArray::Unbind() const{
		glBindVertexArray(0);
	}
}}