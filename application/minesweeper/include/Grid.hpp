#ifndef MINESWEEPER_GRID_HPP
#define MINESWEEPER_GRID_HPP

#include <vector>

#include "Component/Behavior.hpp"
#include "Utility/Matrix.hpp"
#include "GridNode.hpp"

class Grid;
typedef std::shared_ptr<Grid> GridPtr;
typedef std::weak_ptr<Grid> GridWPtr;

class Grid : public tomengine::Behavior
{
public:
    Grid(const int width, const int height);
    ~Grid();

    void Generate(const int mines);
    void Visualize();
    void Render();
    GridNode GetNode(const int i, const int j);
    void GetNodeAtScreenCoords(const int x, const int y);

private:
    tomengine::Matrix<GridNode> matrix;
    int width;
    int height;

    std::vector<int> GetRandomSequence(int from, int to, int count);
};

#endif