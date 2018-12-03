#ifndef MINESWEEPER_GRID_HPP
#define MINESWEEPER_GRID_HPP

#include "Utility/Matrix.hpp"
#include "GridNode.hpp"

class Grid
{
public:
    Grid(const int width, const int height);

private:
    tomengine::Matrix<GridNode> matrix;
    int width;
    int height;

    void Generate();
};

#endif