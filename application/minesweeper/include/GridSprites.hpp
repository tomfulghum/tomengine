#ifndef MINESWEEPER_GRID_SPRITES_HPP
#define MINESWEEPER_GRID_SPRITES_HPP

#include <vector>

#include "Common.hpp"

#include "GridNode.hpp"

class GridSprites
{
public:
    static void Load();
    static tomengine::SpritePtr GetSprite(NodeState state);
    static bool IsInitialized();

private:
    static std::vector<tomengine::SpritePtr> sprites;
    static bool initialized;
};

#endif