#include "EntityManager.hpp"

using namespace tomengine;

std::list<EntityPtr> EntityManager::entities;

EntityPtr EntityManager::CreateEntity()
{
    // Dumb pointer because Entity constructor is protected (can't use make_shared)
    Entity* entity = new Entity();
    entities.push_back(std::shared_ptr<Entity>(entity));
    return entities.back();
}

void EntityManager::RemoveEntity(EntityPtr pEntity)
{
    entities.remove(pEntity);
}

void EntityManager::InitEntities()
{
    for (auto& iEntity : entities) {
        iEntity->Init();
    }
}

void EntityManager::UpdateEntities()
{
    for (auto& iEntity : entities) {
        if (iEntity->IsActive()) {
            iEntity->Update();
        }
    }
}

void EntityManager::RenderEntities()
{
    for (auto& iEntity : entities) {
        if (iEntity->IsActive()) {
            iEntity->Render();
        }
    }
}