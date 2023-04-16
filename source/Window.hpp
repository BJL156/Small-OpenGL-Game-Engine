#pragma once

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <GLM/glm.hpp>

#include <iostream>

namespace Engine {
	class Window {
	public:
		Window(uint32_t width, uint32_t height, const char* title);
		~Window();

		void update();

		void clearColor(glm::vec3 color);

		bool shouldClose() { return glfwWindowShouldClose(window); }

		uint32_t getWidth() { return width; }
		uint32_t getHeight() { return height; }
		GLFWwindow* getWindow() { return window; }
	private:
		void createGLFWWindow();

		GLFWwindow* window;
		uint32_t width = 0, height = 0;
		const char* title;
	};
}