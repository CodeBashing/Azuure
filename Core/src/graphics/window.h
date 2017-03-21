#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

namespace azuure { namespace graphics {
	class Window {
	public:
		Window(const char* title, int width, int height);
		~Window();

		bool Closed() const;
		inline int GetWidth() const;
		inline int GetHeight() const;

		void Clear() const;
		void Update();
	private:
		bool Init();
		static void WindowResize(GLFWwindow* window, int width, int height);
	private:
		GLFWwindow* m_window;

		const char* m_title;
		int m_width, m_height;
		bool m_Closed;
	};
}}



