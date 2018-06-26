//
//  Mesh.hpp
//  Land
//
//  Created by Dexter Burk on 6/26/18.
//  Copyright © 2018 Dexter Burk. All rights reserved.
//

#pragma once

#include <GL/glew.h>

class Mesh {
    unsigned int count;
    
public:
    Mesh(unsigned int count);
    
    void object();
    void pointer(unsigned int index, unsigned int vertex);
};
