//
//  Camera.hpp
//  Land
//
//  Created by Dexter Burk on 6/26/18.
//  Copyright © 2018 Dexter Burk. All rights reserved.
//

#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
    glm::vec3 position, rotation;
    
public:
    Camera();
    Camera(glm::vec3 position, glm::vec3 rotation);
    
    void relative(glm::vec3 position, glm::vec3 rotation);
    
    glm::vec3 getPosition();
    void setPosition(glm::vec3 position);
    
    glm::vec3 getRotation();
    void setRotation(glm::vec3 rotation);
};
