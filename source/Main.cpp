#include "Window.hpp"
#include <iostream>

int main() {
    Engine::Window window(800, 600, "OpenGL is cool ig");

    window.clearColor(glm::vec3(127.0f, 239.0f, 183.0f));

    while (!window.shouldClose()) {
        window.update();

    }

    return 0;
}