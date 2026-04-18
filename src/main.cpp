#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {
    if (!glfwInit()) {
        return -1;
    }

    std::cout << "Engine Starting..." << std::endl;

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(640, 480, "Placeholder", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Load OpenGL function pointers using GLAD
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up and exit
    glfwTerminate();
    return 0;
}