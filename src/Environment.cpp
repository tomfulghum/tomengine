#include "Environment.hpp"

#include <iostream>

using namespace tomengine;

// Initialize static variables
ApplicationPtr Environment::App;
GLFWwindow* Environment::Window;
int Environment::WindowWidth = 800;
int Environment::WindowHeight = 600;
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
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

    glViewport(0, 0, WindowWidth, WindowHeight);
    glEnable(GL_CULL_FACE);
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

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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
    std::cout << "Window dimensions: " << pWidth << "x" << pHeight << std::endl;
}