#include "../headers/VBO.h"

VBO::VBO(std::vector<Vertex>& vertices) {
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cerr << "OpenGL Error during VBO initialization: " << glewGetErrorString(error) << std::endl;
        return;
    }
}

void VBO::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete() {
    glDeleteBuffers(1, &ID);
}