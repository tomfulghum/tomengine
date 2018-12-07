#ifndef MINESWEEPER_GRIDNODE_HPP
#define MINESWEEPER_GRIDNODE_HPP

#include "Sprite.hpp"

enum NodeState
{
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

class GridNode
{
public:
    GridNode();

    NodeState GetState() const { return this->state; }
    bool IsMine() const { return this->mine; }
    tomengine::SpritePtr GetSprite() const { return this->sprite; }

    void SetState(NodeState state);
    void SetMine(bool mine);
    void SetSprite(tomengine::SpritePtr sprite);

private:
    tomengine::SpritePtr sprite;
    NodeState state;
    bool mine;
};

#endif