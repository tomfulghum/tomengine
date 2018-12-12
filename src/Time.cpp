#include "Time.hpp"

using namespace tomengine;

double Time::deltaTime;
double Time::runTime;

double Time::DeltaTime()
{
    return deltaTime;
}

double Time::RunTime()
{
    return runTime;
}