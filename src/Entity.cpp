#include "Component/Component.hpp"
#include "Entity.hpp"

using namespace tomengine;

Entity::~Entity()
{
    components.clear();
}

void Entity::Update()
{
    for (auto& iComponent : components)
    {
        iComponent->Update();
    }
}

void Entity::Render()
{
    for (auto& iComponent : components)
    {
        iComponent->Render();
    }
}
