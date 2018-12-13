#include "Input.hpp"

using namespace tomengine;

std::array<ButtonAction, 8> Input::mouseButtonStates;
double Input::cursorPosX;
double Input::cursorPosY;

bool Input::GetMouseButton(const MouseButton pButton)
{
    return mouseButtonStates[pButton] == BUTTON_PRESSED;
}

bool Input::GetMouseButtonDown(const MouseButton pButton)
{
    return mouseButtonStates[pButton] == BUTTON_DOWN;
}

bool Input::GetMouseButtonUp(const MouseButton pButton)
{
    return mouseButtonStates[pButton] == BUTTON_UP;
}

glm::vec2 Input::GetCursorPosition()
{
    return glm::vec2(cursorPosX, cursorPosY);
}

void Input::UpdateButtonStates()
{
    for (ButtonAction& action : mouseButtonStates) {
        if (action == BUTTON_DOWN) {
            action = BUTTON_PRESSED;
        } else if (action == BUTTON_UP) {
            action = BUTTON_NONE;
        }
    }
}

MouseButton Input::GetMouseButtonFromGlfw(const int pGlfwButton)
{
    switch (pGlfwButton) {
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