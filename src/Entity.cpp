#include "Entity.hpp"

#include "Component/Component.hpp"

using namespace tomengine;

Entity::Entity() :
    active(true)
{
}

Entity::~Entity()
{
}

void Entity::SetActive(bool pActive)
{
    this->active = pActive;
}

void Entity::Init()
{
    for (auto& iComponent : components) {
        if (iComponent->IsActive()) {
            iComponent->Init();
        }
    }
}

void Entity::Update()
{
    for (auto& iComponent : components) {
        iComponent->Update();
    }
}

void Entity::Render()
{
    for (auto& iComponent : components) {
        iComponent->Render();
    }
}
