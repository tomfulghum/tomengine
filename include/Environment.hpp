#ifndef TOMENGINE_ENVIRONMENT_HPP
#define TOMENGINE_ENVIRONMENT_HPP

#include <memory>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Application.hpp"

namespace tomengine
{

class Environment
{
public:
    static ApplicationPtr App;

    static int GetWindowWidth() { return WindowWidth; }
    static int GetWindowHeight() { return WindowHeight; }
    static glm::mat4 GetOrthoProjectionMatrix() { return OrthoProjMatrix; }
    static float GetDeltaTime() { return DeltaTime; }
    static bool GetKey(int pKey);

    static void SetApplication(ApplicationPtr app);
    static void SetWindowDimensions(int width, int height);
    static void SetWindowTitle(const std::string& title);

    static int Initialize();
    static void Update();
    static void Terminate();

private:
    Environment();

    static GLFWwindow* Window;
    static int WindowWidth;
    static int WindowHeight;
    static glm::mat4 OrthoProjMatrix;
    static std::string WindowTitle;
    static float LastFrameTime;
    static float DeltaTime;
    static bool Keys[1024];

    static void SetKey(int key, bool pressed);
    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
    static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
    static void APIENTRY GlDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
};

} // namespace tomengine

#endif