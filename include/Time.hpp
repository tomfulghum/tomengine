#ifndef TOMENGINE_TIME_HPP
#define TOMENGINE_TIME_HPP

namespace tomengine
{

class Time
{
    friend class Environment;

public:
    static double DeltaTime();
    static double RunTime();

private:
    static double deltaTime;
    static double runTime;
};

} // namespace tomengine

#endif