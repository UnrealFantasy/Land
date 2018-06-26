//
//  Shader.hpp
//  Land
//
//  Created by Dexter Burk on 6/26/18.
//  Copyright © 2018 Dexter Burk. All rights reserved.
//

#pragma once

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

class Shader {
    unsigned int programID;
public:
    Shader(const char* vertex, const char* fragment);
    
    void bind(bool use);
    
    void s_matrix4(const char* uniform, glm::mat4 matrix);
    void s_matrix3(const char* uniform, glm::mat3 matrix);
    void s_matrix2(const char* uniform, glm::mat2 matrix);
    
    void s_vector4(const char* uniform, glm::vec4 vector);
    void s_vector3(const char* uniform, glm::vec3 vector);
    void s_vector2(const char* uniform, glm::vec2 vector);
    
    void s_float(const char* uniform, float value);
    void s_int(const char* uniform, int value);
private:
    unsigned int shader(const char* glsl, GLenum type);
    
    unsigned int s_loc(const char* uniform);
};
