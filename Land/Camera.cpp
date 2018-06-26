//
//  Camera.cpp
//  Land
//
//  Created by Dexter Burk on 6/26/18.
//  Copyright © 2018 Dexter Burk. All rights reserved.
//

#include "Camera.hpp"

Camera::Camera()
{
    position = rotation = glm::vec3(0, 0, 0);
}

Camera::Camera(glm::vec3 position, glm::vec3 rotation)
{
    Camera::position = position;
    Camera::rotation = rotation;
}

void Camera::relative(glm::vec3 position, glm::vec3 rotation)
{
    Camera::position += position;
    Camera::rotation += rotation;
}

glm::vec3 Camera::getPosition()
{
    return position;
}

void Camera::setPosition(glm::vec3 position)
{
    Camera::position = position;
}

glm::vec3 Camera::getRotation()
{
    return rotation;
}

void Camera::setRotation(glm::vec3 rotation)
{
    Camera::rotation = rotation;
}
