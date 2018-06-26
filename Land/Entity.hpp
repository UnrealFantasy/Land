//
//  Entity.hpp
//  Land
//
//  Created by Dexter Burk on 6/26/18.
//  Copyright © 2018 Dexter Burk. All rights reserved.
//

#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Entity {
    glm::vec3 position, rotation;
    
    float scale;
    
public:
    Entity(glm::vec3 position, glm::vec3 rotation, float scale);
    
    void relative(glm::vec3 position, glm::vec3 rotation, float scale);
    
    glm::vec3 getPosition();
    void setPosition(glm::vec3 position);
    
    glm::vec3 getRotation();
    void setRotation(glm::vec3 rotation);
    
    float getScale();
    void setScale(float);
};
