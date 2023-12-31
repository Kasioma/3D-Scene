#include "../headers/Model.h"

std::string relative        = "C:/Users/maria/OneDrive/Desktop/uni/graphics/scene/textures/";
std::string relativeShaders = "C:/Users/maria/OneDrive/Desktop/uni/graphics/scene/shaders/";
std::string relativeModels  = "C:/Users/maria/OneDrive/Desktop/uni/graphics/scene/models/";
const unsigned int width    = 800;
const unsigned int height   = 800;

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

    Shader shaderProgram((relativeShaders + "default.vert").c_str(), (relativeShaders + "default.frag").c_str());

    glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    glm::vec3 lightPos   = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::mat4 lightModel = glm::mat4(1.0f);
    lightModel           = glm::translate(lightModel, lightPos);

    shaderProgram.Activate();
    glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
    glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

    glEnable(GL_DEPTH_TEST);

    Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

    Model model((relativeModels + "sword/scene.gltf").c_str());

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        camera.Inputs(window);
        camera.updateMatrix(45.0f, 0.1f, 100.0f);

        model.Draw(shaderProgram, camera);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    shaderProgram.Deactivate();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
