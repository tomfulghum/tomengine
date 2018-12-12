#ifndef TOMENGINE_COMPONENT_COMPONENT_HPP
#define TOMENGINE_COMPONENT_COMPONENT_HPP

#include "Common.hpp"

/*
 Macros used to implement component classes
 Usage:
  In header file: COMPONENT_DECLARATION(classname)
  In cpp file: COMPONENT_DEFINITION(parentname, classname)
*/

#define TO_STRING(x) #x

#define COMPONENT_DECLARATION(componentName) \
public:                                      \
    static const std::size_t Type;           \
    virtual bool IsClassType(const std::size_t classType) const override;

#define COMPONENT_DEFINITION(parent, child)                                     \
    const std::size_t child::Type = std::hash<std::string>()(TO_STRING(child)); \
    bool child::IsClassType(const std::size_t classType) const                  \
    {                                                                           \
        if (classType == child::Type)                                           \
        {                                                                       \
            return true;                                                        \
        }                                                                       \
        return parent::IsClassType(classType);                                  \
    }

namespace tomengine
{

class Component
{
    friend class Entity;

public:
    Component() {}
    virtual ~Component() = default;

    static const std::size_t Type;
    virtual bool IsClassType(const std::size_t classType) const { return classType == Type; }

    EntityWPtr GetEntity() { return this->entity; }

    virtual void Update() = 0;
    virtual void Render() = 0;

protected:
    EntityWPtr entity;
};

} // namespace tomengine

#endif