//
//  Shader.cpp
//  Land
//
//  Created by Dexter Burk on 6/26/18.
//  Copyright © 2018 Dexter Burk. All rights reserved.
//

#include "Shader.hpp"

Shader::Shader(const char* vertex, const char* fragment)
{
    programID = glCreateProgram();
    
    glAttachShader(programID, shader(vertex, GL_VERTEX_SHADER));
    glAttachShader(programID, shader(fragment, GL_FRAGMENT_SHADER));
    
    glLinkProgram(programID);
    glValidateProgram(programID);
}

void Shader::bind(bool use)
{
    if(use)
        glUseProgram(programID);
    else
        glUseProgram(0);
}

void Shader::s_matrix4(const char* uniform, glm::mat4 matrix)
{
    glUniformMatrix4fv(s_loc(uniform), 1, GL_FALSE, &matrix[0][0]);
}

void Shader::s_matrix3(const char* uniform, glm::mat3 matrix)
{
    glUniformMatrix3fv(s_loc(uniform), 1, GL_FALSE, &matrix[0][0]);
}

void Shader::s_matrix2(const char* uniform, glm::mat2 matrix)
{
    glUniformMatrix2fv(s_loc(uniform), 1, GL_FALSE, &matrix[0][0]);
}

void Shader::s_vector4(const char* uniform, glm::vec4 vector)
{
    glUniform4f(s_loc(uniform), vector.x, vector.y, vector.z, vector.w);
}

void Shader::s_vector3(const char* uniform, glm::vec3 vector)
{
    glUniform3f(s_loc(uniform), vector.x, vector.y, vector.z);
}

void Shader::s_vector2(const char* uniform, glm::vec2 vector)
{
    glUniform2f(s_loc(uniform), vector.x, vector.y);
}

void Shader::s_float(const char* uniform, float value)
{
    glUniform1f(s_loc(uniform), value);
}

void Shader::s_int(const char* uniform, int value)
{
    glUniform1i(s_loc(uniform), value);
}

unsigned int Shader::shader(const char* glsl, GLenum type)
{
    unsigned int shaderID = glCreateShader(type);
    
    glShaderSource(shaderID, 1, &glsl, NULL);
    glCompileShader(shaderID);
    
    GLint success;
    
    char log[4096];
    
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    
    if(!success)
    {
        glGetShaderInfoLog(shaderID, 4096, NULL, log);
        
        std::cout << "Shader compilation failed -> " << type << std::endl;
        std::cout << log << std::endl;
    }
    
    return shaderID;
}

unsigned int Shader::s_loc(const char* uniform)
{
    return glGetUniformLocation(programID, uniform);
}
