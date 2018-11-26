#ifndef TOMENGINE_APPLICATION_HPP
#define TOMENGINE_APPLICATION_HPP

#include <memory>

namespace tomengine
{

class Application;
typedef std::shared_ptr<Application> ApplicationPtr;
typedef std::weak_ptr<Application> ApplicationPtrW;

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