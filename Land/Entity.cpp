//
//  Entity.cpp
//  Land
//
//  Created by Dexter Burk on 6/26/18.
//  Copyright © 2018 Dexter Burk. All rights reserved.
//

#include "Entity.hpp"

Entity::Entity(glm::vec3 position, glm::vec3 rotation, float scale)
{
    Entity::position = position;
    Entity::rotation = rotation;
    Entity::scale = scale;
}

void Entity::relative(glm::vec3 position, glm::vec3 rotation, float scale)
{
    Entity::position += position;
    Entity::rotation += rotation;
}

glm::vec3 Entity::getPosition()
{
    return position;
}

void Entity::setPosition(glm::vec3 position)
{
    Entity::position = position;
}

glm::vec3 Entity::getRotation()
{
    return rotation;
}

void Entity::setRotation(glm::vec3 rotation)
{
    Entity::rotation = rotation;
}

float Entity::getScale()
{
    return scale;
}

void Entity::setScale(float scale)
{
    Entity::scale = scale;
}
