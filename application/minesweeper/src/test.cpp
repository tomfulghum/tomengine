#include "Environment.hpp"

using namespace tomengine;

int main(int argc, char const* argv[])
{
    Environment::Initialize();
    Environment::Update();
    Environment::Terminate();

    return 0;
}