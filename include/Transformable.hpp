#ifndef TOMENGINE_TRANSFORMABLE_HPP
#define TOMENGINE_TRANSFORMABLE_HPP

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace tomengine
{

struct Transform
{
    glm::vec3 scale;
    glm::vec3 pivot;
    float rotation;
    glm::vec3 position;
};

class Transformable
{
public:
    Transformable();

    const Transform& GetTransform() { return this->transform; }
    glm::vec3 GetScale() { return this->transform.scale; }
    glm::vec3 GetPivot() { return this->transform.pivot; }
    float GetRotation() { return this->transform.rotation; }
    glm::vec3 GetPosition() { return this->transform.position; }
    glm::mat4 GetTransformMatrix();

    void SetScale(const glm::vec3& pScale);
    void SetScale(const float pX, const float pY, const float pZ);
    void SetScale(const float pX, const float pY);
    void SetPivot(const glm::vec3& pPivot);
    void SetPivot(const float pX, const float pY, const float pZ);
    void SetPivot(const float pX, const float pY);
    void SetRotation(const float rotation);
    void SetPosition(const glm::vec3& pPosition);
    void SetPosition(const float pX, const float pY, const float pZ);
    void SetPosition(const float pX, const float pY);

protected:
    Transform transform;
    glm::mat4 transformMatrix;
    bool changed;

    void CalculateTransformMatrix();
};

} // namespace tomengine

#endif