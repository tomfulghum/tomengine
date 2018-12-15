#ifndef MINESWEEPER_GRID_HPP
#define MINESWEEPER_GRID_HPP

#include <vector>

#include "Common.hpp"
#include "Utility/Matrix.hpp"

class Grid;
typedef std::shared_ptr<Grid> GridPtr;
typedef std::weak_ptr<Grid> GridWPtr;

class Grid
{
public:
    Grid(const int width, const int height, const int nodeSize);
    ~Grid();

    tomengine::EntityPtr GetNode(const int i, const int j);
    tomengine::EntityPtr GetNodeAtScreenCoords(const int x, const int y);

    void Generate(const int mines);
    void Visualize();

private:
    tomengine::Matrix<tomengine::EntityPtr> matrix;
    const int width;
    const int height;
    const int nodeSize;

    std::vector<int> GetRandomSequence(int from, int to, int count);
};

#endif