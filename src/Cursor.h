#pragma once

#include "Task.h"

class Cursor : public Task
{
public:
    Cursor();
    virtual ~Cursor() = default;
    bool update() override;
    void draw() const override;

private:
    void move();

    float _x, _y;   //À•W
    int _image;
};

