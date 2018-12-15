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
    // Initialize nodes
    for (int i = 0; i < this->width; i++) {
        for (int j = 0; j < this->height; j++) {
            EntityPtr node = EntityManager::CreateEntity();
            node->AddComponent<SpriteRenderer>();
            node->AddComponent<GridNode>(this, i, j, nodeSize);
            node->SetParent(this);

            node->SetPosition(i * nodeSize, j * nodeSize);
            node->GetComponent<SpriteRenderer>()->SetSprite(GridSprites::GetSprite(BLANK));

            this->matrix.Set(i, j, node);
        }
    }

    std::vector<int> mineCoords = GetRandomSequence(0, this->width * this->height, pMines);

    // Randomly set mines
    for (int i = 0; i < pMines; i++) {
        matrix.Get(mineCoords.back())->GetComponent<GridNode>()->mine = true;
        this->mines.push_back(matrix.Get(mineCoords.back()));
        mineCoords.pop_back();
    }

    // Set number of neighboring mines for each node
    for (int i = 0; i < this->width; i++) {
        for (int j = 0; j < this->height; j++) {
            int mines = 0;

            auto neighbors = GetNeighbors(i, j);
            for (auto& neighbor : neighbors) {
                if (neighbor->GetComponent<GridNode>()->mine) {
                    mines++;
                }
            }

            matrix.Get(i, j)->GetComponent<GridNode>()->nearbyMines = mines;
        }
    }
}

void Grid::Visualize()
{
    for (int i = 0; i < this->width; i++) {
        for (int j = 0; j < this->height; j++) {
            if (matrix.Get(i, j)->GetComponent<GridNode>()->mine) {
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

std::vector<EntityPtr> Grid::GetNeighbors(const int pI, const int pJ)
{
    std::vector<EntityPtr> neighbors;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int x = pI + i;
            int y = pJ + j;

            // Check matrix boundaries
            if (x >= 0 && x < this->width && y >= 0 && y < this->height) {
                // Exclude middle
                if (!(x == pI && y == pJ)) {
                    neighbors.push_back(matrix.Get(x, y));
                }
            }
        }
    }

    return neighbors;
}

std::vector<EntityPtr> Grid::GetMines()
{
    return this->mines;
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