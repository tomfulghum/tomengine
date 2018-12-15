#ifndef MINESWEEPER_GRIDNODE_HPP
#define MINESWEEPER_GRIDNODE_HPP

#include "Component/Component.hpp"
#include "Component/Behavior.hpp"
#include "Component/SpriteRenderer.hpp"

enum NodeState {
    BLANK,
    FLAGGED,
    OPEN_1,
    OPEN_2,
    OPEN_3,
    OPEN_4,
    OPEN_5,
    OPEN_6,
    OPEN_7,
    OPEN_8,
    OPEN_BLANK,
    OPEN_MINE,
    OPEN_MINE_CLICKED
};

class GridNode : public tomengine::Behavior
{
    COMPONENT_DECLARATION(GridNode);

public:
    GridNode(const int posX, const int posY, const int size);

    NodeState GetState() const { return this->state; }
    bool IsMine() const { return this->mine; }

    void SetState(NodeState state);
    void SetMine(bool mine);

    void Start() override;
    void Update() override;

private:
    const int posX;
    const int posY;
    const int size;
    NodeState state;
    bool mine;
    tomengine::SpriteRenderer spriteRenderer;
};

#endif