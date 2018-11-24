#ifndef TOMENGINE_APPLICATION_HPP
#define TOMENGINE_APPLICATION_HPP

namespace tomengine
{
    class Application
    {
        public:
        Application();
        ~Application();

        virtual void Initialize() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
    };
}

#endif