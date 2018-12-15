#include "Transformable.hpp"

using namespace tomengine;

Transformable::Transformable() :
    parent(nullptr)
{
    global.scale = glm::vec3(1.0f);
    global.baseScale = glm::vec3(1.0f);
    global.pivot = glm::vec3(0.0f);
    global.rotation = 0.0f;
    global.position = glm::vec3(0.0f);

    local.scale = glm::vec3(1.0f);
    local.baseScale = glm::vec3(1.0f);
    local.pivot = glm::vec3(0.0f);
    local.rotation = 0.0f;
    local.position = glm::vec3(0.0f);
    CalculateTransformMatrix();
}

void Transformable::SetParent(Transformable* pParent)
{
    if (this->parent != nullptr) {
        this->parent->children.remove(this);
    }

    this->parent = pParent;
    this->parent->children.push_back(this);
    this->SetChanged();
}

glm::mat4 Transformable::GetTransformMatrix()
{
    if (this->changed) {
        CalculateTransformMatrix();
        this->changed = false;
    }
    return this->transformMatrix;
}

void Transformable::SetScale(const glm::vec3& pScale)
{
    this->local.scale = pScale;
    this->SetChanged();
}

void Transformable::SetScale(const float pX, const float pY, const float pZ)
{
    this->SetScale(glm::vec3(pX, pY, pZ));
}

void Transformable::SetScale(const float pX, const float pY)
{
    this->SetScale(glm::vec3(pX, pY, 1.0f));
}
void Transformable::SetBaseScale(const glm::vec3& pScale)
{
    this->local.baseScale = pScale;
    this->SetChanged();
}

void Transformable::SetBaseScale(const float pX, const float pY, const float pZ)
{
    this->SetBaseScale(glm::vec3(pX, pY, pZ));
}

void Transformable::SetBaseScale(const float pX, const float pY)
{
    this->SetBaseScale(glm::vec3(pX, pY, 1.0f));
}

void Transformable::SetPivot(const glm::vec3& pPivot)
{
    this->local.pivot = pPivot;
    this->SetChanged();
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
    this->local.rotation = glm::radians(pRotation);
    this->SetChanged();
}

void Transformable::SetRotationRadians(const float pRotation)
{
    this->local.rotation = pRotation;
    this->SetChanged();
}

void Transformable::SetPosition(const glm::vec3& pPosition)
{
    this->local.position = pPosition;
    this->SetChanged();
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
    glm::vec3 scale = this->local.scale * this->local.baseScale;
    glm::vec3 pivot = this->local.pivot * scale;
    glm::mat4 trans = glm::mat4(1.0f);

    // Translation
    trans = glm::translate(trans, this->local.position - pivot);

    // Rotation
    trans = glm::translate(trans, glm::vec3(pivot.x, pivot.y, 0.0f));
    trans = glm::rotate(trans, this->local.rotation, glm::vec3(0.0f, 0.0f, 1.0f));
    trans = glm::translate(trans, glm::vec3(-pivot.x, -pivot.y, 0.0f));

    // Scale
    trans = glm::scale(trans, scale);

    if (this->parent != nullptr) {
        trans = this->parent->GetTransformMatrix() * trans;
    }

    this->transformMatrix = trans;
}

void Transformable::SetChanged()
{
    this->changed = true;
    this->UpdateGlobal();
    for (auto& child : children) {
        child->SetChanged();
    }
}

void Transformable::UpdateGlobal()
{
    if (this->parent != nullptr) {
        this->global.scale = this->parent->global.scale * this->local.scale;
        this->global.baseScale = this->parent->global.baseScale * this->local.scale;
        this->global.pivot = this->parent->global.pivot + this->local.pivot;
        this->global.rotation = this->parent->global.rotation + this->local.rotation;
        this->global.position = this->parent->global.position + this->local.position - this->parent->global.pivot;
    } else {
        this->global.scale = this->local.scale;
        this->global.baseScale = this->local.scale;
        this->global.pivot = this->local.pivot;
        this->global.rotation = this->local.rotation;
        this->global.position = this->local.position;
    }
}