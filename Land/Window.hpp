//
//  Window.hpp
//  Land
//
//  Created by Dexter Burk on 6/26/18.
//  Copyright © 2018 Dexter Burk. All rights reserved.
//

#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

class Window {
    unsigned int width, height;
    
    const char* title;
    
    GLFWwindow* handle;
    
public:
    Window(unsigned int width, unsigned int height, const char* title);
    
    void create();
    
    void clear();
    void update();
    
    void close();
    
    unsigned int getWidth();
    unsigned int getHeight();
    
    const char* getTitle();
    
    GLFWwindow* getHandle();
    
    float getAspect();
    bool getKey(unsigned int key);
};
