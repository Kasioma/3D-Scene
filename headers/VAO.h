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

    void Bind();
    void Unbind();
    void Delete();
};

#endif