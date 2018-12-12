#ifndef TOMENGINE_TRANSFORMABLE_HPP
#define TOMENGINE_TRANSFORMABLE_HPP

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace tomengine
{

struct Transform
{
    glm::vec3 scale;
    glm::vec3 baseScale;
    glm::vec3 pivot;
    float rotation;
    glm::vec3 position;
};

class Transformable
{
public:
    Transformable();

    const Transform& GetTransform() const { return this->transform; }
    glm::vec3 GetScale() const { return this->transform.scale; }
    glm::vec3 GetPivot() const { return this->transform.pivot; }
    float GetRotation() const { return this->transform.rotation; }
    glm::vec3 GetPosition() const { return this->transform.position; }
    glm::mat4 GetTransformMatrix();

    void SetScale(const glm::vec3& scale);
    void SetScale(const float x, const float y, const float z);
    void SetScale(const float x, const float y);
    void SetPivot(const glm::vec3& pivot);
    void SetPivot(const float x, const float y, const float z);
    void SetPivot(const float x, const float y);
    void SetRotation(const float rotation);
    void SetRotationRadians(const float rotation);
    void SetPosition(const glm::vec3& position);
    void SetPosition(const float x, const float y, const float z);
    void SetPosition(const float x, const float y);

protected:
    Transform transform;
    glm::mat4 transformMatrix;
    bool changed;

    void CalculateTransformMatrix();
};

} // namespace tomengine

#endif