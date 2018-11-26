#ifndef TOMENGINE_ENTITY_ENTITY_HPP
#define TOMENGINE_ENTITY_ENTITY_HPP

#include <memory>

#include "Transformable.hpp"

namespace tomengine
{

class Entity;
typedef std::shared_ptr<Entity> EntityPtr;
typedef std::weak_ptr<Entity> EntityPtrW;

class Entity : public Transformable
{
public:
    Entity() {}
    ~Entity() {}

    virtual void Update() {}
    virtual void Render() {}
};

} // namespace tomengine

#endif