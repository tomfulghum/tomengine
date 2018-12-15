#ifndef TOMENGINE_ENTITY_ENTITY_HPP
#define TOMENGINE_ENTITY_ENTITY_HPP

#include <algorithm>
#include <vector>

#include "Common.hpp"
#include "Component/Component.hpp"
#include "Transformable.hpp"

namespace tomengine
{

class Entity : public Transformable, public std::enable_shared_from_this<Entity>
{
    friend class EntityManager;

public:
    virtual ~Entity();

    bool IsActive() { return this->active; }
    void SetActive(bool active);

    virtual void Init();
    virtual void Update();
    virtual void Render();

    template <class ComponentType, typename... Args>
    void AddComponent(Args&&... parameters);

    template <class ComponentType>
    ComponentType* GetComponent();

    template <class ComponentType>
    bool RemoveComponent();

protected:
    Entity();

private:
    std::vector<ComponentUPtr> components;
    bool active;
};

template <class ComponentType, typename... Args>
void Entity::AddComponent(Args&&... parameters)
{
    components.emplace_back(std::make_unique<ComponentType>(std::forward<Args>(parameters)...));
    components.back()->entity = shared_from_this();
}

template <class ComponentType>
ComponentType* Entity::GetComponent()
{
    for (auto&& iComponent : components) {
        if (iComponent->IsClassType(ComponentType::Type)) {
            return static_cast<ComponentType*>(iComponent.get());
        }
    }

    return nullptr;
}

template <class ComponentType>
bool Entity::RemoveComponent()
{
    if (components.empty()) {
        return false;
    }

    auto isClassType = [classType = ComponentType::Type](auto& component) { return component->IsClassType(classType); };
    auto& index = std::find_if(components.begin(), components.end(), isClassType);

    bool success = index != components.end();

    if (success) {
        components.erase(index);
    }

    return success;
}

} // namespace tomengine

#endif