#include "Window.hpp"

namespace Engine {
	Window::Window(uint32_t width, uint32_t height, const char* title)
		: width(width), height(height), title(title) {
		createGLFWWindow();
	}

	Window::~Window() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void Window::update() {
		glfwSwapBuffers(window);
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::clearColor(glm::vec3 color) {
		glClearColor(color.x / 255.0f, color.y / 255.0f, color.z / 255.0f, 1.0f);
	}

	void Window::createGLFWWindow() {
		if (!glfwInit()) {
			std::cerr << "GLFW::INITALIZE::Failed to initialize GLFW." << std::endl;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, title, nullptr, nullptr);
		if (window == nullptr) {
			std::cerr << "GLFW::WINDOW::Failed to create GLFW window." << std::endl;
		}
		glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cerr << "GLAD::INITIALIZE::Failed to initialize GLAD." << std::endl;
		}
	}
}