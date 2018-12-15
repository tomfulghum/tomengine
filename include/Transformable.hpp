#ifndef TOMENGINE_TRANSFORMABLE_HPP
#define TOMENGINE_TRANSFORMABLE_HPP

#include <list>

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace tomengine
{

struct Transform {
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

    void SetParent(Transformable* parent);
    Transformable* GetParent() const { return this->parent; }

    const Transform& GetTransform() const { return this->global; }
    const Transform& GetLocalTransform() const { return this->local; }
    glm::vec3 GetScale() const { return this->global.scale; }
    glm::vec3 GetLocalScale() const { return this->local.scale; }
    glm::vec3 GetPivot() const { return this->local.pivot; }
    float GetRotation() const { return this->global.rotation; }
    float GetLocalRotation() const { return this->local.rotation; }
    glm::vec3 GetPosition() const { return this->global.position; }
    glm::vec3 GetLocalPosition() const { return this->local.position; }
    glm::mat4 GetTransformMatrix();

    void SetScale(const glm::vec3& scale);
    void SetScale(const float x, const float y, const float z);
    void SetScale(const float x, const float y);
    void SetBaseScale(const glm::vec3& scale);
    void SetBaseScale(const float x, const float y, const float z);
    void SetBaseScale(const float x, const float y);
    void SetPivot(const glm::vec3& pivot);
    void SetPivot(const float x, const float y, const float z);
    void SetPivot(const float x, const float y);
    void SetRotation(const float rotation);
    void SetRotationRadians(const float rotation);
    void SetPosition(const glm::vec3& position);
    void SetPosition(const float x, const float y, const float z);
    void SetPosition(const float x, const float y);

protected:
    Transformable* parent;
    std::list<Transformable*> children;
    Transform local;
    Transform global;
    glm::mat4 transformMatrix;
    bool changed;

private:
    void CalculateTransformMatrix();
    void SetChanged();
    void UpdateGlobal();
};

} // namespace tomengine

#endif