#pragma once

//GLEW
#include <GL\glew.h>

//GLM
#include <glm\glm.hpp>
#include <glm/gtc/type_ptr.hpp>

//STD
#include <vector>
#include <iostream>

//CUSTOM
#include "../utils/fileutils.h"

namespace azuure { namespace graphics {
	class Shader {
	public:
		Shader(const char *vertexPath, const char* fragmentPath);
		~Shader();

		inline GLuint GetID() const { return m_shaderID; }

		void Enable();
		void Disable();

		void SetUniform2f(const GLchar *name, const glm::vec2 &vector);
		void SetUniform3f(const GLchar *name, const glm::vec3 &vector);
		void SetUniform4f(const GLchar *name, const glm::vec4 &vector);
		void SetUniformMat4(const GLchar *name, const glm::mat4 &matrix);
	private:
		GLuint Load();
		inline GLint GetUniformLocation(const GLchar *name) { return glGetUniformLocation(m_shaderID, name); }
	private:
		const char *m_vertexPath, *m_fragmentPath;

		GLuint m_shaderID;
	};
}}