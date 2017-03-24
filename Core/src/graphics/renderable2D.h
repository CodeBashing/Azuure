#pragma once

//GLM
#include <glm\glm.hpp>

//CUSTOM
#include "buffers\buffer.h"
#include "buffers\indexbuffer.h"
#include "buffers\vertexarray.h"
#include "shader.h"

namespace azuure { namespace graphics {
	class Renderable2D {
	public:
		Renderable2D(glm::vec2 size, glm::vec3 position, glm::vec4 color, Shader &shader) 
			:m_size(size), m_position(position), m_color(color), m_shader(shader)
		{
			m_VAO = new VertexArray();
			GLfloat vertices[] = {
				0, 0, 0,
				0, size.y, 0,
				size.x, size.y, 0,
				size.x, 0, 0,
			};
			GLfloat colors[] = {
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w
			};

			m_VAO->AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
			m_VAO->AddBuffer(new Buffer(colors, 4 * 4, 4), 1);

			GLushort indices[] = { 0, 1, 2, 2, 3, 0 };
			m_IBO = new IndexBuffer(indices, 6);
		}

		~Renderable2D()
		{
			delete m_VAO;
			delete m_IBO;
		}

		inline const glm::vec2& GetSize() const { return m_size; }
		inline const glm::vec3& GetPosition() const { return m_position; }
		inline const glm::vec4& GetColor() const { return m_color; }

		inline Shader& GetShader() const { return m_shader; }

		inline const VertexArray* GetVAO() const { return m_VAO; }
		inline const IndexBuffer* GetIBO() const { return m_IBO; }
	protected:
		glm::vec2 m_size;
		glm::vec3 m_position;
		glm::vec4 m_color;

		VertexArray *m_VAO;
		IndexBuffer *m_IBO;

		Shader &m_shader;
		
	};
}}