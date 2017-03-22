#pragma once

//GLEW
#include <GL\glew.h>

//GLFW
#include <GLFW\glfw3.h>

//STD
#include <iostream>

namespace azuure { namespace graphics {
	class Window {
	public:
		Window(const char *title, int width, int height);
		~Window();

		inline int GetWidth() const { return m_width; }
		inline int GetHeight() const { return m_height; };

		void Clear() const;
		void Update();
		bool Closed() const;
	private:
		bool Init();
		static void WindowResize(GLFWwindow *window, int width, int height);
	private:
		GLFWwindow *m_window;

		const char *m_title;
		int m_width, m_height;
		bool m_Closed;
	};
}}



