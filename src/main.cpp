#include "../headers/Mesh.h"

std::string relative        = "C:/Users/maria/OneDrive/Desktop/uni/graphics/scene/textures/";
std::string relativeShaders = "C:/Users/maria/OneDrive/Desktop/uni/graphics/scene/shaders/";
const unsigned int width    = 800;
const unsigned int height   = 800;

Vertex vertices[] = {
    Vertex{ glm::vec3(-0.5f, 0.0f, 0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(-1.0f, 0.0f) },   // Bottom side
    Vertex{ glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(0.0f, 5.0f, 0.0f), glm::vec2(-1.0f, 0.0f) },  // Bottom side
    Vertex{ glm::vec3(0.5f, 0.0f, -0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(5.0f, 5.0f, 0.0f), glm::vec2(-1.0f, 0.0f) },   // Bottom side
    Vertex{ glm::vec3(0.5f, 0.0f, 0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(5.0f, 0.0f, 0.0f), glm::vec2(-1.0f, 0.0f) },    // Bottom side

    Vertex{ glm::vec3(-0.5f, 0.0f, 0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(0.0f, 0.0f, -0.8f), glm::vec2(0.5f, 0.0f) },   // Left Side
    Vertex{ glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(5.0f, 0.0f, -0.8f), glm::vec2(0.5f, 0.0f) },  // Left Side
    Vertex{ glm::vec3(0.0f, 0.8f, 0.0f), glm::vec3(0.92f, 0.86f, 0.76f), glm::vec3(2.5f, 5.0f, -0.8f), glm::vec2(0.5f, 0.0f) },    // Left Side

    Vertex{ glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(5.0f, 0.0f, 0.0f), glm::vec2(0.5f, -0.8f) },  // Non-facing side
    Vertex{ glm::vec3(0.5f, 0.0f, -0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(0.5f, -0.8f) },   // Non-facing side
    Vertex{ glm::vec3(0.0f, 0.8f, 0.0f), glm::vec3(0.92f, 0.86f, 0.76f), glm::vec3(2.5f, 5.0f, 0.0f), glm::vec2(0.5f, -0.8f) },    // Non-facing side

    Vertex{ glm::vec3(0.5f, 0.0f, -0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(0.0f, 0.0f, 0.8f), glm::vec2(0.5f, 0.0f) },  // Right side
    Vertex{ glm::vec3(0.5f, 0.0f, 0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(5.0f, 0.0f, 0.8f), glm::vec2(0.5f, 0.0f) },   // Right side
    Vertex{ glm::vec3(0.0f, 0.8f, 0.0f), glm::vec3(0.92f, 0.86f, 0.76f), glm::vec3(2.5f, 5.0f, 0.8f), glm::vec2(0.5f, 0.0f) },   // Right side

    Vertex{ glm::vec3(0.5f, 0.0f, 0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(5.0f, 0.0f, 0.0f), glm::vec2(0.5f, 0.8f) },   // Facing side
    Vertex{ glm::vec3(-0.5f, 0.0f, 0.5f), glm::vec3(0.83f, 0.70f, 0.44f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(0.5f, 0.8f) },  // Facing side
    Vertex{ glm::vec3(0.0f, 0.8f, 0.0f), glm::vec3(0.92f, 0.86f, 0.76f), glm::vec3(2.5f, 5.0f, 0.0f), glm::vec2(0.5f, 0.8f) }    // Facing side
};

GLuint indices[] = {
    0, 1, 2,     // Bottom side
    0, 2, 3,     // Bottom side
    4, 6, 5,     // Left side
    7, 9, 8,     // Non-facing side
    10, 12, 11,  // Right side
    13, 15, 14   // Facing side
};

Vertex lightVertices[] = {
    Vertex{ glm::vec3(-0.1f, -0.1f, 0.1f) },
    Vertex{ glm::vec3(-0.1f, -0.1f, -0.1f) },
    Vertex{ glm::vec3(0.1f, -0.1f, -0.1f) },
    Vertex{ glm::vec3(0.1f, -0.1f, 0.1f) },
    Vertex{ glm::vec3(-0.1f, 0.1f, 0.1f) },
    Vertex{ glm::vec3(-0.1f, 0.1f, -0.1f) },
    Vertex{ glm::vec3(0.1f, 0.1f, -0.1f) },
    Vertex{ glm::vec3(0.1f, 0.1f, 0.1f) }
};

GLuint lightIndices[] = {
    0, 1, 2,
    0, 2, 3,
    0, 4, 7,
    0, 7, 3,
    3, 7, 6,
    3, 6, 2,
    2, 6, 5,
    2, 5, 1,
    1, 5, 4,
    1, 4, 0,
    4, 5, 6,
    4, 6, 7
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

    Texture textures[]{
        Texture((relative + "bricks.png").c_str(), "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE)
    };

    Shader shaderProgram((relativeShaders + "default.vert").c_str(), (relativeShaders + "default.frag").c_str());
    std::vector<Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
    std::vector<GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));
    std::vector<Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));
    Mesh floor(verts, ind, tex);

    Shader lightShader((relativeShaders + "light.vert").c_str(), (relativeShaders + "light.frag").c_str());
    std::vector<Vertex> lightVerts(lightVertices, lightVertices + sizeof(lightVertices) / sizeof(Vertex));
    std::vector<GLuint> lightInd(lightIndices, lightIndices + sizeof(lightIndices) / sizeof(GLuint));
    Mesh light(lightVerts, lightInd, tex);

    glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    glm::vec3 lightPos   = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::mat4 lightModel = glm::mat4(1.0f);
    lightModel           = glm::translate(lightModel, lightPos);

    glm::vec3 pyramidPos   = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::mat4 pyramidModel = glm::mat4(1.0f);
    pyramidModel           = glm::translate(pyramidModel, pyramidPos);

    lightShader.Activate();
    glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
    glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
    shaderProgram.Activate();
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
    glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
    glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

    glEnable(GL_DEPTH_TEST);

    Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        camera.Inputs(window);
        camera.updateMatrix(45.0f, 0.1f, 100.0f);

        floor.Draw(shaderProgram, camera);
        light.Draw(lightShader, camera);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    shaderProgram.Deactivate();
    lightShader.Deactivate();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
