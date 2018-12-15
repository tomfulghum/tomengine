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

// Declares variables and functions needed for determining component type
#define COMPONENT_DECLARATION(componentName) \
public:                                      \
    static const std::size_t Type;           \
    virtual bool IsClassType(const std::size_t classType) const override;

// Implements the variables and functions declared by COMPONENT_DECLARATION
#define COMPONENT_DEFINITION(parent, child)                                     \
    const std::size_t child::Type = std::hash<std::string>()(TO_STRING(child)); \
    bool child::IsClassType(const std::size_t classType) const                  \
    {                                                                           \
        if (classType == child::Type) {                                         \
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
    Component();
    virtual ~Component() = default;

    static const std::size_t Type;
    virtual bool IsClassType(const std::size_t classType) const { return classType == Type; }

    EntityWPtr GetEntity() { return this->entity; }

    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;

    bool IsActive() { return this->active; }
    bool IsInitialized() { return this->initialized; }
    void SetActive(bool active);

protected:
    void Init();

    EntityWPtr entity;
    bool active;
    bool initialized;
};

} // namespace tomengine

#endif