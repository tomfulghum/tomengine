#ifndef MINESWEEPER_GRID_SPRITES_HPP
#define MINESWEEPER_GRID_SPRITES_HPP

#include <vector>

#include "Common.hpp"

#include "GridNode.hpp"

enum NodeSprite {
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

class GridSprites
{
public:
    static void Load();
    static tomengine::SpritePtr GetSprite(NodeSprite Sprite);
    static bool IsInitialized();

private:
    static std::vector<tomengine::SpritePtr> sprites;
    static bool initialized;
};

#endif