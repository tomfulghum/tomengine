#include "Grid.hpp"

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>

#include "Entity.hpp"
#include "EntityManager.hpp"

#include "GridNode.hpp"
#include "GridSprites.hpp"

using namespace tomengine;

Grid::Grid(const int pWidth, const int pHeight, const int pNodeSize) :
    width(pWidth), height(pHeight), nodeSize(pNodeSize), matrix(pWidth, pHeight)
{
}

Grid::~Grid()
{
}

void Grid::Generate(const int pMines)
{
    for (int i = 0; i < this->width; i++) {
        for (int j = 0; j < this->height; j++) {
            EntityPtr node = EntityManager::CreateEntity();
            node->AddComponent<SpriteRenderer>();
            node->AddComponent<GridNode>(i, j, nodeSize);

            node->SetPosition(i * nodeSize, j * nodeSize);
            node->GetComponent<SpriteRenderer>().SetSprite(GridSprites::GetSprite(BLANK));

            this->matrix.Set(i, j, node);
        }
    }

    std::vector<int> mineCoords = GetRandomSequence(0, this->width * this->height, pMines);

    for (int i = 0; i < pMines; i++) {
        matrix.Get(mineCoords.back())->GetComponent<GridNode>().SetMine(true);
        mineCoords.pop_back();
    }
}

void Grid::Visualize()
{
    for (int i = 0; i < this->width; i++) {
        for (int j = 0; j < this->height; j++) {
            if (matrix.Get(i, j)->GetComponent<GridNode>().IsMine()) {
                std::cout << "X";
            } else {
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }
}

EntityPtr Grid::GetNode(const int pI, const int pJ)
{
    return matrix.Get(pI, pJ);
}

EntityPtr GetNodeAtScreenCoords(const int x, const int y)
{
}

std::vector<int> Grid::GetRandomSequence(int pFrom, int pTo, int pCount)
{
    std::vector<int> numbers;
    std::vector<int> sequence;

    for (int i = pFrom; i < pTo; i++) {
        numbers.push_back(i);
    }

    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));

    for (int i = 0; i < pCount; i++) {
        sequence.push_back(numbers.back());
        numbers.pop_back();
    }

    return sequence;
}