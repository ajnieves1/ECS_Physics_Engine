#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {
    // 1. Setup GLFW
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Physics Engine", NULL, NULL);
    glfwMakeContextCurrent(window);

    // Initialize GLAD (
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // OpenGL logic
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    // Loads OpenGL function pointers using GLAD
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up and exit
    glfwTerminate();
    return 0;
}