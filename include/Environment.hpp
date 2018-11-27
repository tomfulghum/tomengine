#ifndef TOMENGINE_ENVIRONMENT_HPP
#define TOMENGINE_ENVIRONMENT_HPP

#include <memory>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Application.hpp"

namespace tomengine
{

class Environment;
typedef std::shared_ptr<Environment> EnvironmentPtr;
typedef std::weak_ptr<Environment> EnvironmentPtrW;

class Environment
{
public:
    static ApplicationPtr App;

    static int GetWindowWidth() { return WindowWidth; }
    static int GetWindowHeight() { return WindowHeight; }
    static float GetDeltaTime() { return DeltaTime; }
    static bool GetKey(int pKey);

    static void SetApplication(ApplicationPtr pApp);
    static void SetWindowDimensions(int pWidth, int pHeight);
    static void SetWindowTitle(const std::string& pTitle);

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
    static void APIENTRY GlDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
};

} // namespace tomengine

#endif