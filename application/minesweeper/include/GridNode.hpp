#ifndef MINESWEEPER_GRIDNODE_HPP
#define MINESWEEPER_GRIDNODE_HPP

#include "Component/Component.hpp"
#include "Component/Behavior.hpp"
#include "Component/SpriteRenderer.hpp"

#include "Grid.hpp"

class GridNode : public tomengine::Behavior
{
    COMPONENT_DECLARATION(GridNode);

    friend class Grid;

public:
    GridNode(Grid* grid, const int posX, const int posY, const int size);

    void Open();
    void Reveal();
    void Reset();

    void Start() override;
    void Update() override;

private:
    Grid* grid;
    const int posX;
    const int posY;
    const int size;
    int nearbyMines;
    bool open;
    bool flagged;
    bool mine;
    tomengine::SpriteRenderer* spriteRenderer;
};

#endif