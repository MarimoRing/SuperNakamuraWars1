#pragma once

#include "Enum.h"
#include "AbstractScene.h"
#include "Parameter.h"

class IOnSceneChangedListener
{
public:
    IOnSceneChangedListener() = default;
    virtual ~IOnSceneChangedListener() = default;
    virtual void onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear) = 0;
};

