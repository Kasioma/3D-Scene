#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include "../headers/EBO.h"
#include "../headers/Shader.h"
#include "../headers/Texture.h"
#include "../headers/VAO.h"
#include "../headers/VBO.h"

std::string relative      = "C:/Users/maria/OneDrive/Desktop/uni/graphics/scene/textures/";
const unsigned int width  = 800;
const unsigned int height = 800;

GLfloat vertices[] = {
    -0.5f, 0.0f, 0.5f, 0.83f, 0.70f, 0.44f, 0.0f, 0.0f,
    -0.5f, 0.0f, -0.5f, 0.83f, 0.70f, 0.44f, 5.0f, 0.0f,
    0.5f, 0.0f, -0.5f, 0.83f, 0.70f, 0.44f, 0.0f, 0.0f,
    0.5f, 0.0f, 0.5f, 0.83f, 0.70f, 0.44f, 5.0f, 0.0f,
    0.0f, 0.8f, 0.0f, 0.92f, 0.86f, 0.76f, 2.5f, 5.0f
};

GLuint indices[] = {
    0, 1, 2,
    0, 2, 3,
    0, 1, 4,
    1, 2, 4,
    2, 3, 4,
    3, 0, 4
};
int main() {
    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(width, height, "Scene", NULL, NULL);
    if (!window) {
        std::cout << "failed";
        glfwTerminate();
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        std::cout << "Error: Failed to initialize" << std::endl;

    glViewport(0, 0, width, height);

    Shader shaderProgram("C:/Users/maria/OneDrive/Desktop/uni/graphics/scene/shaders/default.vert", "C:/Users/maria/OneDrive/Desktop/uni/graphics/scene/shaders/default.frag");

    VAO VAO1;
    VAO1.Bind();
    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));

    VAO1.linkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
    VAO1.linkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    VAO1.linkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    Texture bricks((relative + "bricks.png").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    bricks.texUnit(shaderProgram, "tex0", 0);

    float rotation  = 0.0f;
    double prevTime = glfwGetTime();

    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 view  = glm::mat4(1.0f);
        glm::mat4 proj  = glm::mat4(1.0f);
        model           = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));
        view            = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
        proj            = glm::perspective(glm::radians(45.0f), float(width / height), 0.1f, 100.0f);
        int modelLoc    = glGetUniformLocation(shaderProgram.ID, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));
        shaderProgram.Activate();

        double current = glfwGetTime();
        if (current - prevTime >= 1 / 60) {
            rotation += 0.01f;
            prevTime = current;
        }
        bricks.Bind();
        VAO1.Bind();

        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    bricks.Delete();
    shaderProgram.Deactivate();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
