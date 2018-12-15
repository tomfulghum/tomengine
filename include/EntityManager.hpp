#ifndef TOMENGINE_ENTITY_MANAGER_HPP
#define TOMENGINE_ENTITY_MANAGER_HPP

#include <list>

#include "Common.hpp"
#include "Entity.hpp"

namespace tomengine
{

class EntityManager
{
public:
    static EntityPtr CreateEntity();
    static void RemoveEntity(EntityPtr entity);

    static void InitEntities();
    static void UpdateEntities();
    static void RenderEntities();

private:
    EntityManager();

    static std::list<EntityPtr> entities;
};

} // namespace tomengine

#endif