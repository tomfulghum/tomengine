#include "GridNode.hpp"

#include <iostream>

#include "Entity.hpp"
#include "Input.hpp"

using namespace tomengine;

COMPONENT_DEFINITION(Behavior, GridNode)

GridNode::GridNode(const int pPosX, const int pPosY, const int pSize) :
    Behavior(), posX(pPosX), posY(pPosY), size(pSize), state(FLAGGED), mine(false)
{
}

void GridNode::Start()
{
    this->spriteRenderer = this->entity.lock()->GetComponent<SpriteRenderer>();
}

void GridNode::Update()
{
    glm::vec2 cursorPos = Input::GetCursorPosition();
    bool mouseover = false;
    int pixelPosX = this->posX * this->size;
    int pixelPosY = this->posY * this->size;

    if (cursorPos.x >= pixelPosX && cursorPos.x < pixelPosX + this->size) {
        if (cursorPos.y >= pixelPosY && cursorPos.y < pixelPosY + this->size) {
            if (Input::GetMouseButtonDown(MOUSE_0)) {
                std::cout << this->posX << " " << this->posY << std::endl;
            }
        }
    }
}

void GridNode::SetState(NodeState pState)
{
    this->state = pState;
}

void GridNode::SetMine(bool pMine)
{
    this->mine = pMine;
}