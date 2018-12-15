#ifndef MINESWEEPER_GRID_HPP
#define MINESWEEPER_GRID_HPP

#include <vector>

#include "Common.hpp"
#include "Transformable.hpp"
#include "Utility/Matrix.hpp"

class Grid;
typedef std::shared_ptr<Grid> GridPtr;
typedef std::weak_ptr<Grid> GridWPtr;

class Grid : public tomengine::Transformable
{
public:
    Grid(const int width, const int height, const int nodeSize);
    ~Grid();

    tomengine::EntityPtr GetNode(const int i, const int j);
    std::vector<tomengine::EntityPtr> GetNeighbors(const int i, const int j);
    std::vector<tomengine::EntityPtr> GetMines();

    void Generate(const int mines);
    void Visualize();

private:
    tomengine::Matrix<tomengine::EntityPtr> matrix;
    std::vector<tomengine::EntityPtr> mines;
    const int width;
    const int height;
    const int nodeSize;

    std::vector<int> GetRandomSequence(int from, int to, int count);
};

#endif