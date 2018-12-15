#include "GridNode.hpp"

#include <iostream>

#include "Entity.hpp"
#include "Input.hpp"

#include "GridSprites.hpp"

using namespace tomengine;

COMPONENT_DEFINITION(Behavior, GridNode)

GridNode::GridNode(Grid* pGrid, const int pPosX, const int pPosY, const int pSize) :
    Behavior(), grid(pGrid), posX(pPosX), posY(pPosY), size(pSize), nearbyMines(0), open(false), flagged(false), mine(false)
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
                std::cout << this->posX << " " << this->posY << " Mines: " << this->nearbyMines << std::endl;

                if (!this->open && !this->flagged) {
                    this->Open();
                }
            } else if (Input::GetMouseButtonDown(MOUSE_1)) {
                if (!this->open) {
                    if (!this->flagged) {
                        this->spriteRenderer->SetSprite(GridSprites::GetSprite(FLAGGED));
                        this->flagged = true;
                    } else {
                        this->spriteRenderer->SetSprite(GridSprites::GetSprite(BLANK));
                        this->flagged = false;
                    }
                }
            }
        }
    }
}

void GridNode::Open()
{
    this->open = true;

    if (this->mine) {
        auto mines = grid->GetMines();
        for (auto& mine : mines) {
            mine->GetComponent<GridNode>()->Reveal();
        }
        this->spriteRenderer->SetSprite(GridSprites::GetSprite(OPEN_MINE_CLICKED));
    } else if (this->nearbyMines == 0) {
        this->spriteRenderer->SetSprite(GridSprites::GetSprite(OPEN_BLANK));

        auto neighbors = grid->GetNeighbors(this->posX, this->posY);
        for (auto& neighbor : neighbors) {
            GridNode* node = neighbor->GetComponent<GridNode>();
            if (!node->open && !node->mine) {
                node->Open();
            }
        }
    } else {
        this->spriteRenderer->SetSprite(GridSprites::GetSprite((NodeSprite)(FLAGGED + nearbyMines)));
    }
}

void GridNode::Reveal()
{
    this->open = true;

    if (this->mine) {
        this->spriteRenderer->SetSprite(GridSprites::GetSprite(OPEN_MINE));
    }
}