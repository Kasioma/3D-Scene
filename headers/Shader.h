#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <cerrno>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#define GLEW_STATIC
#include <GL/glew.h>

std::string getFileContents(const char* filename);

class Shader {
   public:
    GLuint ID;
    Shader(const char* vertexFile, const char* fragmentFile);

    void Activate();
    void Deactivate();
    void compileErrors(unsigned int shader, const char* type);
};

#endif