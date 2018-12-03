#ifndef TOMENGINE_TIME_HPP
#define TOMENGINE_TIME_HPP

namespace tomengine
{

class Time
{
    friend class Environment;

public:
    static float DeltaTime();

private:
    static float deltaTime;
};

} // namespace tomengine

#endif