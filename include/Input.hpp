#ifndef TOMENGINE_INPUT_HPP
#define TOMENGINE_INPUT_HPP

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <array>

namespace tomengine
{

enum ButtonAction
{
    BUTTON_NONE,
    BUTTON_DOWN,
    BUTTON_PRESSED,
    BUTTON_UP
};

enum MouseButton
{
    MOUSE_INVALID,
    MOUSE_0,
    MOUSE_1,
    MOUSE_2,
    MOUSE_3,
    MOUSE_4,
    MOUSE_5,
    MOUSE_6,
    MOUSE_7
};

class Input
{
    friend class Environment;

public:
    static bool GetMouseButton(const MouseButton button);
    static bool GetMouseButtonDown(const MouseButton button);
    static bool GetMouseButtonUp(const MouseButton button);
    static glm::vec2 GetCursorPosition();

private:
    static std::array<ButtonAction, 8> mouseButtonStates;

    static double cursorPosX;
    static double cursorPosY;

    static void UpdateButtonStates();
    static MouseButton GetMouseButtonFromGlfw(const int glfwButton);
};

} // namespace tomengine

#endif