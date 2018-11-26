#ifndef TOMENGINE_APPLICATION_MINESWEEPER_HPP
#define TOMENGINE_APPLICATION_MINESWEEPER_HPP

#include "Application.hpp"

class Minesweeper : public tomengine::Application
{
public:
    Minesweeper();
    ~Minesweeper();

    void Initialize() override;
    void Update() override;
    void Render() override;
    void Terminate() override;
};

#endif