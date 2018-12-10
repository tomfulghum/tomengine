#ifndef TOMENGINE_APPLICATION_HPP
#define TOMENGINE_APPLICATION_HPP

#include "Common.hpp"

namespace tomengine
{

class Application
{
public:
    virtual void Initialize() {}
    virtual void Update() {}
    virtual void Render() {}
    virtual void Terminate() {}

protected:
    Application() {}
};

} // namespace tomengine

#endif