#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#define GLEW_STATIC
#include <GL/glew.h>

#include <cerrno>
#include <glm/glm.hpp>
#include <iostream>
#include <vector>

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec3 color;
    glm::vec2 texUV;
};

class VBO {
   public:
    GLuint ID;
    VBO(std::vector<Vertex>& vertices);
    void Bind();
    void Unbind();
    void Delete();
};

#endif