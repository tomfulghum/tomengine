#include "Input.hpp"

using namespace tomengine;

std::array<ButtonAction, 8> Input::mouseButtonStates;

bool Input::GetMouseButton(MouseButton pButton)
{
    return mouseButtonStates[pButton] == BUTTON_PRESSED;
}

bool Input::GetMouseButtonDown(MouseButton pButton)
{
    return mouseButtonStates[pButton] == BUTTON_DOWN;
}

bool Input::GetMouseButtonUp(MouseButton pButton)
{
    return mouseButtonStates[pButton] == BUTTON_UP;
}

void Input::UpdateButtonStates()
{
    for (ButtonAction& action : mouseButtonStates)
    {
        if (action == BUTTON_DOWN)
        {
            action = BUTTON_PRESSED;
        }
        else if (action == BUTTON_UP)
        {
            action = BUTTON_NONE;
        }
    }
}

MouseButton Input::GetMouseButtonFromGlfw(int pGlfwButton)
{
    switch (pGlfwButton)
    {
        case (GLFW_MOUSE_BUTTON_1): return MOUSE_0;
        case (GLFW_MOUSE_BUTTON_2): return MOUSE_1;
        case (GLFW_MOUSE_BUTTON_3): return MOUSE_2;
        case (GLFW_MOUSE_BUTTON_4): return MOUSE_3;
        case (GLFW_MOUSE_BUTTON_5): return MOUSE_4;
        case (GLFW_MOUSE_BUTTON_6): return MOUSE_5;
        case (GLFW_MOUSE_BUTTON_7): return MOUSE_6;
        case (GLFW_MOUSE_BUTTON_8): return MOUSE_7;
        default: return MOUSE_INVALID;
    }
}