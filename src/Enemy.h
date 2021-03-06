#pragma once

#include "Task.h"

class Enemy : public Task
{
public:
    Enemy(float x, float y);
    virtual ~Enemy() = default;
    bool update() override;
    void draw() const override;

protected:
    float _x, _y;//座標
    float _speed;//速さ
    float _angle;//角度
};

