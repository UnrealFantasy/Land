//
//  Mesh.cpp
//  Land
//
//  Created by Dexter Burk on 6/26/18.
//  Copyright © 2018 Dexter Burk. All rights reserved.
//

#include "Mesh.hpp"

Mesh::Mesh(unsigned int count)
{
    Mesh::count = count;
    
    unsigned int vaoID;
    
    glGenVertexArrays(1, &vaoID);
    glBindVertexArray(vaoID);
}

void Mesh::object()
{
    unsigned int vboID;
    
    glGenBuffers(1, &vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
}

void Mesh::pointer(unsigned int index, unsigned int vertex)
{
    glVertexAttribPointer(index, vertex, GL_FLOAT, GL_FALSE, vertex * sizeof(float), (void*)0);
    glEnableVertexAttribArray(index);
}
