#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#define GLEW_STATIC
#include <GL/glew.h>

#include <cerrno>
#include <iostream>

class VBO {
   public:
    GLuint ID;
    VBO(GLfloat* vertices, GLsizeiptr size);
    void Bind();
    void Unbind();
    void Delete();
};

#endif