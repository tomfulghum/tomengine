#include "GridNode.hpp"

using namespace tomengine;

GridNode::GridNode() :
    state(FLAGGED), mine(false)
{
}

void GridNode::SetState(NodeState pState)
{
    this->state = pState;
}

void GridNode::SetMine(bool pMine)
{
    this->mine = pMine;
}

void GridNode::SetSprite(SpritePtr pSprite)
{
    this->sprite = pSprite;
}