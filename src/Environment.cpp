#include "Environment.hpp"

#include <iostream>

#include <glm/gtc/matrix_transform.hpp>

using namespace tomengine;

// Initialize static variables
ApplicationPtr Environment::App;
GLFWwindow* Environment::Window;
int Environment::WindowWidth = 800;
int Environment::WindowHeight = 600;
glm::mat4 Environment::OrthoProjMatrix = glm::mat4(0.0f);
std::string Environment::WindowTitle = "TomEngine";
float Environment::LastFrameTime;
float Environment::DeltaTime;
bool Environment::Keys[1024];

bool Environment::GetKey(int pKey)
{
    return Keys[pKey];
}

void Environment::SetApplication(ApplicationPtr pApp)
{
    App = pApp;
}

void Environment::SetWindowDimensions(int pWidth, int pHeight)
{
    if (Window)
    {
        FramebufferSizeCallback(Window, pWidth, pHeight);
    }
}

void Environment::SetWindowTitle(const std::string& pTitle)
{
    WindowTitle = pTitle;
}

int Environment::Initialize()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

    Window = glfwCreateWindow(WindowWidth, WindowHeight, WindowTitle.c_str(), NULL, NULL);
    if (Window == NULL)
    {
        std::cout << "ERROR::Environment: Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(Window);

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

    glViewport(0, 0, WindowWidth, WindowHeight);
    //glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glfwSetKeyCallback(Window, KeyCallback);
    glfwSetFramebufferSizeCallback(Window, FramebufferSizeCallback);

    if (App)
    {
        App->Initialize();
    }

    return 0;
}

void Environment::Update()
{
    while (!glfwWindowShouldClose(Window))
    {
        float currentFrameTime = glfwGetTime();
        DeltaTime = currentFrameTime - LastFrameTime;
        LastFrameTime = currentFrameTime;

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        if (App)
        {
            App->Update();
            App->Render();
        }

        glfwPollEvents();
        glfwSwapBuffers(Window);
    }
}

void Environment::Terminate()
{
    if (App)
    {
        App->Terminate();
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

void Environment::KeyCallback(GLFWwindow* pWindow, int pKey, int pScancode, int pAction, int pMode)
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

void Environment::FramebufferSizeCallback(GLFWwindow* pWindow, int pWidth, int pHeight)
{
    WindowWidth = pWidth;
    WindowHeight = pHeight;
    glViewport(0, 0, pWidth, pHeight);
    OrthoProjMatrix = glm::ortho(0.0f, static_cast<GLfloat>(WindowWidth), static_cast<GLfloat>(WindowHeight), 0.0f, -1.0f, 1.0f);
    std::cout << "Window dimensions: " << pWidth << "x" << pHeight << std::endl;
}

void APIENTRY Environment::GlDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
    // ignore non-significant error/warning codes
    if (id == 131169 || id == 131185 || id == 131218 || id == 131204)
        return;

    std::cout << "---------------" << std::endl;
    std::cout << "Debug message (" << id << "): " << message << std::endl;

    switch (source)
    {
    case GL_DEBUG_SOURCE_API: std::cout << "Source: API"; break;
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM: std::cout << "Source: Window System"; break;
    case GL_DEBUG_SOURCE_SHADER_COMPILER: std::cout << "Source: Shader Compiler"; break;
    case GL_DEBUG_SOURCE_THIRD_PARTY: std::cout << "Source: Third Party"; break;
    case GL_DEBUG_SOURCE_APPLICATION: std::cout << "Source: Application"; break;
    case GL_DEBUG_SOURCE_OTHER: std::cout << "Source: Other"; break;
    }
    std::cout << std::endl;

    switch (type)
    {
    case GL_DEBUG_TYPE_ERROR: std::cout << "Type: Error"; break;
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: std::cout << "Type: Deprecated Behaviour"; break;
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: std::cout << "Type: Undefined Behaviour"; break;
    case GL_DEBUG_TYPE_PORTABILITY: std::cout << "Type: Portability"; break;
    case GL_DEBUG_TYPE_PERFORMANCE: std::cout << "Type: Performance"; break;
    case GL_DEBUG_TYPE_MARKER: std::cout << "Type: Marker"; break;
    case GL_DEBUG_TYPE_PUSH_GROUP: std::cout << "Type: Push Group"; break;
    case GL_DEBUG_TYPE_POP_GROUP: std::cout << "Type: Pop Group"; break;
    case GL_DEBUG_TYPE_OTHER: std::cout << "Type: Other"; break;
    }
    std::cout << std::endl;

    switch (severity)
    {
    case GL_DEBUG_SEVERITY_HIGH: std::cout << "Severity: high"; break;
    case GL_DEBUG_SEVERITY_MEDIUM: std::cout << "Severity: medium"; break;
    case GL_DEBUG_SEVERITY_LOW: std::cout << "Severity: low"; break;
    case GL_DEBUG_SEVERITY_NOTIFICATION: std::cout << "Severity: notification"; break;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}