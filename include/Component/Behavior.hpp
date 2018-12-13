#ifndef TOMENGINE_COMPONENT_BEHAVIOR_HPP
#define TOMENGINE_COMPONENT_BEHAVIOR_HPP

#include "Component/Component.hpp"

namespace tomengine
{

class Behavior : public Component
{
    COMPONENT_DECLARATION(Behavior);

public:
    Behavior();
    ~Behavior();

private:
};

} // namespace tomengine

#endif
