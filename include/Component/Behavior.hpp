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

    virtual void Start() override;
    virtual void Update() override;
    void Render() override {}

private:
};

} // namespace tomengine

#endif
