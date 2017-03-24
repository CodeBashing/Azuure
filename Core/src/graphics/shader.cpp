#include "shader.h"


namespace azuure { namespace graphics {
	/*Constructor and Destructor*/
	Shader::Shader(const char *vertexPath, const char *fragmentPath)
		:m_vertexPath(vertexPath), m_fragmentPath(fragmentPath)
	{
		m_shaderID = Load();
	}
	Shader::~Shader()
	{
		glDeleteProgram(m_shaderID);
	}

	/*Public Methodes*/
	void Shader::Enable() {
		glUseProgram(m_shaderID);
	}
	void Shader::Disable() {
		glUseProgram(0);
	}

	void Shader::SetUniform2f(const GLchar *name, const glm::vec2 & vector) {
		glUniform2f(GetUniformLocation(name), vector.x, vector.y);
	}
	void Shader::SetUniform3f(const GLchar *name, const glm::vec3 & vector) {
		glUniform3f(GetUniformLocation(name), vector.x, vector.y, vector.z);
	}
	void Shader::SetUniform4f(const GLchar *name, const glm::vec4 & vector) {
		glUniform4f(GetUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
	}
	void Shader::SetUniformMat4(const GLchar *name, const glm::mat4 & matrix) {
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
	}

	/*Private Methodes*/
	GLuint Shader::Load() {
		//Create program and shaders ID's
		GLuint program = glCreateProgram();
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		//Get the shader sources
		const GLchar* vertexSource;
		const GLchar* fragmentSource;
		glShaderSource(vertexShader, 1, &(vertexSource = utils::readFile(m_vertexPath).c_str()), NULL);
		glShaderSource(fragmentShader, 1, &(fragmentSource = utils::readFile(m_fragmentPath).c_str()), NULL);

		//Compile Shaders
		glCompileShader(vertexShader);
		glCompileShader(fragmentShader);

		//Handle errors
		GLint result;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE) {
			GLint length;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(vertexShader, length, &length, &error[0]);
			std::cerr << &error[0] << std::endl;
			glDeleteShader(vertexShader);
			return 0;
		}
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE) {
			GLint length;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(fragmentShader, length, &length, &error[0]);
			std::cerr << &error[0] << std::endl;
			glDeleteShader(fragmentShader);
			return 0;
		}

		glAttachShader(program, vertexShader);
		glAttachShader(program, fragmentShader);
		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		return program;
	}
}}