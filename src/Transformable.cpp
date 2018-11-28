#include "Transformable.hpp"

using namespace tomengine;

Transformable::Transformable()
{
    transform.scale = glm::vec3(1.0f);
    transform.pivot = glm::vec3(0.0f);
    transform.rotation = 0.0f;
    transform.position = glm::vec3(0.0f);
    CalculateTransformMatrix();
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

void Transformable::SetScale(const glm::vec3& pScale)
{
    this->transform.scale = pScale;
    this->changed = true;
}

void Transformable::SetScale(const float pX, const float pY, const float pZ)
{
    this->SetScale(glm::vec3(pX, pY, pZ));
}

void Transformable::SetScale(const float pX, const float pY)
{
    this->SetScale(glm::vec3(pX, pY, 0.0f));
}

void Transformable::SetPivot(const glm::vec3& pPivot)
{
    this->transform.pivot = pPivot;
    this->changed = true;
}

void Transformable::SetPivot(const float pX, const float pY, const float pZ)
{
    this->SetPivot(glm::vec3(pX, pY, pZ));
}

void Transformable::SetPivot(const float pX, const float pY)
{
    this->SetPivot(glm::vec3(pX, pY, 0.0f));
}

void Transformable::SetRotation(const float pRotation)
{
    this->transform.rotation = pRotation;
    this->changed = true;
}

void Transformable::SetPosition(const glm::vec3& pPosition)
{
    this->transform.position = pPosition;
    this->changed = true;
}

void Transformable::SetPosition(const float pX, const float pY, const float pZ)
{
    this->SetPosition(glm::vec3(pX, pY, pZ));
}

void Transformable::SetPosition(const float pX, const float pY)
{
    this->SetPosition(glm::vec3(pX, pY, 0.0f));
}

void Transformable::CalculateTransformMatrix()
{
    glm::mat4 trans = glm::mat4(1.0f);

    // Translation
    trans = glm::translate(trans, this->transform.position);

    // Rotation
    //trans = glm::translate(trans, glm::vec3(this->transform.pivot.x, this->transform.pivot.y, 0.0f));
    trans = glm::rotate(trans, this->transform.rotation, glm::vec3(0.0f, 0.0f, 1.0f));
    trans = glm::translate(trans, glm::vec3(-this->transform.pivot.x, -this->transform.pivot.y, 0.0f));

    // Scale
    trans = glm::scale(trans, transform.scale);

    this->transformMatrix = trans;
}