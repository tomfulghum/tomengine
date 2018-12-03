#ifndef MINESWEEPER_GRIDNODE_HPP
#define MINESWEEPER_GRIDNODE_HPP

enum NodeState
{
    BLANK,
    OPEN,
    FLAGGED
};

class GridNode
{
public:
    GridNode();

private:
    NodeState state;
    bool mine;
};

#endif