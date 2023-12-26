#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#define GLEW_STATIC
#include <GL/glew.h>

class EBO {
   public:
    GLuint ID;
    EBO(GLuint* indices, GLsizeiptr size);
    void Bind();
    void Unbind();
    void Delete();
};

#endif