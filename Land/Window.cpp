//
//  Window.cpp
//  Land
//
//  Created by Dexter Burk on 6/26/18.
//  Copyright © 2018 Dexter Burk. All rights reserved.
//

#include "Window.hpp"

Window::Window(unsigned int width, unsigned int height, const char* title)
{
    Window::width = width;
    Window::height = height;
    Window::title = title;
}

void Window::create()
{
    if(!glfwInit())
    {
        std::cout << "GLFW failed to properly initialize." << std::endl;
        
        glfwTerminate();
    }
    
    glfwDefaultWindowHints();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    
    handle = glfwCreateWindow(width, height, title, NULL, NULL);
    
    if(!handle)
    {
        std::cout << "GLFW window failed to properly create." << std::endl;
        
        glfwTerminate();
    }
    
    glfwMakeContextCurrent(handle);
    glfwShowWindow(handle);
    
    glewExperimental = GL_TRUE;
    
    if(glewInit() != GLEW_OK)
    {
        std::cout << "GLEW failed to properly initialize." << std::endl;
    }
}

void Window::clear()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::update()
{
    glfwSwapBuffers(handle);
    glfwPollEvents();
}

void Window::close()
{
    glfwDestroyWindow(handle);
    glfwTerminate();
}

unsigned int Window::getWidth()
{
    return width;
}

unsigned int Window::getHeight()
{
    return height;
}

const char* Window::getTitle()
{
    return title;
}

GLFWwindow* Window::getHandle()
{
    return handle;
}

float Window::getAspect()
{
    return (float) width / (float) height;
}

bool Window::getKey(unsigned int key)
{
    return glfwGetKey(handle, key) == GLFW_PRESS;
}
