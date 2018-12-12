#include "Environment.hpp"

#include <chrono>
#include <iostream>

#include <glm/gtc/matrix_transform.hpp>

#include "Application.hpp"
#include "Input.hpp"
#include "Time.hpp"

using namespace tomengine;

// Initialize static variables
ApplicationPtr Environment::app;
GLFWwindow* Environment::window;
int Environment::windowWidth = 1;
int Environment::windowHeight = 1;
glm::mat4 Environment::orthoProjMatrix = glm::mat4(0.0f);
std::string Environment::windowTitle = "TomEngine";
double Environment::lastFrameTime;
bool Environment::Keys[1024];

bool Environment::GetKey(int pKey)
{
    return Keys[pKey];
}

void Environment::SetApplication(ApplicationPtr pApp)
{
    app = pApp;
}

void Environment::SetWindowDimensions(int pWidth, int pHeight)
{
    if (window)
    {
        glfwSetWindowSize(window, pWidth, pHeight);
    }
}

void Environment::SetWindowTitle(const std::string& pTitle)
{
    windowTitle = pTitle;
}

int Environment::Initialize()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

    window = glfwCreateWindow(windowWidth, windowHeight, windowTitle.c_str(), NULL, NULL);
    if (window == NULL)
    {
        std::cout << "ERROR::Environment: Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "ERROR::Environment: Failed to initialize GLAD." << std::endl;
        return -1;
    }

    GLint flags;
    glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
    if (flags & GL_CONTEXT_FLAG_DEBUG_BIT)
    {
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(GlDebugCallback, nullptr);
        glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
    }

    glViewport(0, 0, windowWidth, windowHeight);
    //glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    //glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glfwSetKeyCallback(window, KeyCallback);
    glfwSetCursorPosCallback(window, CursorPositionCallback);
    glfwSetMouseButtonCallback(window, MouseButtonCallback);
    glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

    if (app)
    {
        app->Initialize();
    }

    return 0;
}

void Environment::Run()
{
    while (!glfwWindowShouldClose(window))
    {
        Time::runTime = glfwGetTime();
        Time::deltaTime = Time::runTime - lastFrameTime;
        lastFrameTime = Time::runTime;

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        Input::UpdateButtonStates();
        glfwPollEvents();

        if (app)
        {
            app->Update();
            app->Render();
        }

        glfwSwapBuffers(window);
    }

    Terminate();
}

void Environment::Terminate()
{
    if (app)
    {
        app->Terminate();
    }
    glfwTerminate();
}

void Environment::SetKey(int pKey, bool pPressed)
{
    if (pKey >= 0 && pKey < 1024)
    {
        Keys[pKey] = pPressed;
    }
}

void Environment::KeyCallback(GLFWwindow* pWindow, int pKey, int pScancode, int pAction, int pMods)
{
    if (pKey == GLFW_KEY_ESCAPE && pAction == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }

    if (pAction == GLFW_PRESS)
    {
        SetKey(pKey, true);
        std::cout << pKey << std::endl;
    }
    else if (pAction == GLFW_RELEASE)
    {
        SetKey(pKey, false);
    }
}

void Environment::CursorPositionCallback(GLFWwindow* pWindow, double pPosX, double pPosY)
{
    Input::cursorPosX = pPosX;
    Input::cursorPosY = pPosY;
}

void Environment::MouseButtonCallback(GLFWwindow* pWindow, int pButton, int pAction, int pMods)
{
    switch (pAction)
    {
        case (GLFW_PRESS):
            Input::mouseButtonStates[Input::GetMouseButtonFromGlfw(pButton)] = BUTTON_DOWN;
            break;
        case (GLFW_RELEASE):
            Input::mouseButtonStates[Input::GetMouseButtonFromGlfw(pButton)] = BUTTON_UP;
            break;
    }
}

void Environment::FramebufferSizeCallback(GLFWwindow* pWindow, int pWidth, int pHeight)
{
    windowWidth = pWidth;
    windowHeight = pHeight;
    glViewport(0, 0, pWidth, pHeight);
    orthoProjMatrix = glm::ortho(0.0f, static_cast<GLfloat>(windowWidth), static_cast<GLfloat>(windowHeight), 0.0f, -1.0f, 1.0f);
    std::cout << "Window dimensions: " << pWidth << "x" << pHeight << std::endl;
}

void APIENTRY Environment::GlDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
    // ignore non-significant error/warning codes
    if (id == 131169 || id == 131185 || id == 131218 || id == 131204)
        return;

    std::cout << "--------------- OpenGL ---------------" << std::endl;
    std::cout << "Debug message (" << id << "): " << message << std::endl;

    std::cout << "Source: ";
    switch (source)
    {
        case GL_DEBUG_SOURCE_API: std::cout << "API"; break;
        case GL_DEBUG_SOURCE_WINDOW_SYSTEM: std::cout << "Window System"; break;
        case GL_DEBUG_SOURCE_SHADER_COMPILER: std::cout << "Shader Compiler"; break;
        case GL_DEBUG_SOURCE_THIRD_PARTY: std::cout << "Third Party"; break;
        case GL_DEBUG_SOURCE_APPLICATION: std::cout << "Application"; break;
        case GL_DEBUG_SOURCE_OTHER: std::cout << "Other"; break;
    }
    std::cout << std::endl;

    std::cout << "Type: ";
    switch (type)
    {
        case GL_DEBUG_TYPE_ERROR: std::cout << "Error"; break;
        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: std::cout << "Deprecated Behaviour"; break;
        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: std::cout << "Undefined Behaviour"; break;
        case GL_DEBUG_TYPE_PORTABILITY: std::cout << "Portability"; break;
        case GL_DEBUG_TYPE_PERFORMANCE: std::cout << "Performance"; break;
        case GL_DEBUG_TYPE_MARKER: std::cout << "Marker"; break;
        case GL_DEBUG_TYPE_PUSH_GROUP: std::cout << "Push Group"; break;
        case GL_DEBUG_TYPE_POP_GROUP: std::cout << "Pop Group"; break;
        case GL_DEBUG_TYPE_OTHER: std::cout << "Other"; break;
    }
    std::cout << std::endl;

    std::cout << "Severity: ";
    switch (severity)
    {
        case GL_DEBUG_SEVERITY_HIGH: std::cout << "High"; break;
        case GL_DEBUG_SEVERITY_MEDIUM: std::cout << "Medium"; break;
        case GL_DEBUG_SEVERITY_LOW: std::cout << "Low"; break;
        case GL_DEBUG_SEVERITY_NOTIFICATION: std::cout << "Notification"; break;
    }
    std::cout << std::endl
              << std::endl;
}