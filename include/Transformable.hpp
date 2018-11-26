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
    glm::quat rotation;
    glm::vec3 position;
};

class Transformable
{
public:
    Transformable();

    const Transform& GetTransform() { return this->transform; }
    glm::vec3 GetScale() { return this->transform.scale; }
    glm::vec3 GetPivot() { return this->transform.pivot; }
    glm::quat GetRotation() { return this->transform.rotation; }
    glm::vec3 GetPosition() { return this->transform.position; }
    glm::mat4 GetTransformMatrix();
    glm::vec3 GetEulerAngles();

    void SetScale(const glm::vec3& pScale);
    void SetPivot(const glm::vec3& pPivot);
    void SetRotation(const glm::quat& pRotation);
    void SetRotation(const glm::vec3& pEulerAngles);
    void SetPosition(const glm::vec3& pPosition);

protected:
    Transform transform;
    glm::mat4 transformMatrix;
    bool changed;

    void CalculateTransformMatrix();
};

} // namespace tomengine

#endif