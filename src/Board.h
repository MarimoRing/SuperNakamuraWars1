#pragma once

#include "Task.h"
#include "Enum.h"

class Board final : public Task
{
public:
    Board() = default;
    ~Board() = default;
    bool update() override;
    void draw() const override;

private:
    void drawFrame() const;
};

