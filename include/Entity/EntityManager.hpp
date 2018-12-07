#ifndef TOMENGINE_ENTITY_MANAGER_HPP
#define TOMENGINE_ENTITY_MANAGER_HPP

#include <list>

#include "Entity/Entity.hpp"

namespace tomengine
{

class EntityManager
{
public:
    static EntityPtr CreateEntity();
    static void RemoveEntity(EntityPtr entity);

private:
    EntityManager();

    static std::list<EntityPtr> entities;
};

} // namespace tomengine

#endif