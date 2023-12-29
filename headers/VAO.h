#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#define GLEW_STATIC
#include <GL/glew.h>

#include "VBO.h"

class VAO {
   public:
    GLuint ID;
    VAO();

    void linkVBO(VBO& VBO, GLuint layout);

    void linkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);

    void Bind();
    void Unbind();
    void Delete();
};

#endif