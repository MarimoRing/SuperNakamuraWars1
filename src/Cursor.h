#pragma once

#include "Task.h"

class Cursor : public Task
{
public:
    Cursor();
    virtual ~Cursor() = default;
    bool update() override;
    void draw() const override;
    float _x, _y;   //À•W


private:
    void move();

    int _image;
};

