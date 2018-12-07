#include "Entity/EntityManager.hpp"

using namespace tomengine;

EntityPtr EntityManager::CreateEntity()
{
    EntityPtr entity = std::make_shared<Entity>();
    entities.push_back(entity);
    return entity;
}

void EntityManager::RemoveEntity(EntityPtr pEntity)
{
    entities.remove(pEntity);
}