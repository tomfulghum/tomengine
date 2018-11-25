#ifndef TOMENGINE_APPLICATION_HPP
#define TOMENGINE_APPLICATION_HPP

namespace tomengine
{
class Application
{
public:
    ~Application();

    virtual void Initialize();
    virtual void Update();
    virtual void Render();
    virtual void Terminate();

protected:
    Application();
};
} // namespace tomengine

#endif