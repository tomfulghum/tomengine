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
    static ApplicationPtr Application() { return app; }
    static int WindowWidth() { return windowWidth; }
    static int WindowHeight() { return windowHeight; }
    static glm::mat4 OrthoProjectionMatrix() { return orthoProjMatrix; }
    static bool GetKey(int pKey);

    static void SetApplication(ApplicationPtr app);
    static void SetWindowDimensions(int width, int height);
    static void SetWindowTitle(const std::string& title);

    static int Initialize();
    static void Run();
    static void Terminate();

private:
    Environment();

    static ApplicationPtr app;
    static GLFWwindow* window;
    static int windowWidth;
    static int windowHeight;
    static glm::mat4 orthoProjMatrix;
    static std::string windowTitle;
    static float lastFrameTime;
    static bool Keys[1024];

    static void SetKey(int key, bool pressed);
    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void CursorPositionCallback(GLFWwindow* window, double posX, double posY);
    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
    static void APIENTRY GlDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
};

} // namespace tomengine

#endif