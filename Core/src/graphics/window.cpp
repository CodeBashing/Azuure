#include "window.h"

namespace azuure { namespace graphics {
	/*Constructor and Destructor*/
	Window::Window(const char *title, int width, int height)
	{
		m_title = title;
		m_width = width;
		m_height = height;

		if (!Init()) {
			glfwTerminate();
		}
	}
	Window::~Window()
	{
		glfwTerminate();
	}

	/*Public Methodes*/
	void Window::Clear() const {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void Window::Update() {
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}
	bool Window::Closed() const {
		return glfwWindowShouldClose(m_window);
	}

	/*Private Methodes*/
	bool Window::Init() {
		//Init GLFW
		if (!glfwInit()) {
			std::cerr << "Failed to initialize GLFW!" << std::endl;
			return false;
		}
		//Create window
		m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
		if (!m_window) {
			glfwTerminate();
			std::cerr << "Failed to create window!" << std::endl;
			return false;
		}
		//Create OpenGL context
		glfwMakeContextCurrent(m_window);
		//Make the window resizeable
		glfwSetWindowSizeCallback(m_window, WindowResize);

		//Initialize GLEW
		if (glewInit() != GLEW_OK) {
			std::cerr << "Failed to initialize GLEW!" << std::endl;
			return false;
		}

		std::cout << "OpenGL: " << glGetString(GL_VERSION) << std::endl;
		return true;
	}
	void Window::WindowResize(GLFWwindow *window, int width, int height) {
		glViewport(0, 0, width, height);
	}
}}


