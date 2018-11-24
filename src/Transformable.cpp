#include "Transformable.hpp"

using namespace tomengine;

Transformable::Transformable()
{
    transform.scale = glm::vec3(1.0f);
    transform.pivot = glm::vec3(0.0f);
    transform.rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
    transform.position = glm::vec3(0.0f);
    changed = true;
}

glm::mat4 Transformable::GetTransformMatrix()
{
    if (changed)
    {
        CalculateTransformMatrix();
        changed = false;
    }
    return this->transformMatrix;
}

glm::vec3 Transformable::GetEulerAngles()
{
    return glm::eulerAngles(this->transform.rotation);
}

void Transformable::SetScale(const glm::vec3 &pScale)
{
    this->transform.scale = pScale;
    this->changed = true;
}

void Transformable::SetPivot(const glm::vec3 &pPivot)
{
    this->transform.pivot = pPivot;
    this->changed = true;
}

void Transformable::SetRotation(const glm::quat &pRotation)
{
    this->transform.rotation = pRotation;
    this->changed = true;
}

void Transformable::SetRotation(const glm::vec3 &pEulerAngles)
{
    this->transform.rotation = glm::quat(pEulerAngles);
    this->changed = true;
}

void Transformable::CalculateTransformMatrix()
{
    glm::mat4 translation = glm::translate(glm::mat4(1.0f), this->transform.position); 
    glm::mat4 rotation = glm::mat4_cast(this->transform.rotation);
    glm::mat4 pivot = glm::translate(glm::mat4(1.0f), this->transform.pivot);
    glm::mat4 scale = glm::scale(glm::mat4(1.0f), transform.scale);

    this->transformMatrix = translation * rotation * pivot * scale;
}