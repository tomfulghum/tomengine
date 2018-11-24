#ifndef TOMENGINE_ENVIRONMENT_HPP
#define TOMENGINE_ENVIRONMENT_HPP

#include <iostream>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Application.hpp"

namespace tomengine
{
    class Environment
    {
        public:
        //static Application App;

        static int GetWindowWidth() { return WindowWidth; }
        static int GetWindowHeight() { return WindowHeight; }
        static float GetDeltaTime() { return DeltaTime; }
        static bool GetKey(int pKey);
        
        static void SetWindowDimensions(int pWidth, int pHeight);
        static void SetWindowTitle(const std::string &pTitle);

        static int Initialize();
        static void Update();
        static void Terminate();

        private:
        static GLFWwindow* Window;
        static int WindowWidth;
        static int WindowHeight;
        static std::string WindowTitle;
        static float LastFrameTime;
        static float DeltaTime;
        static bool Keys[1024];

        static void SetKey(int pKey, bool pPressed);
        static void KeyCallback(GLFWwindow* pWindow, int pKey, int pScancode, int pAction, int pMode);
        static void FramebufferSizeCallback(GLFWwindow* pWindow, int pWidth, int pHeight);
    };
} // tomengine

#endif