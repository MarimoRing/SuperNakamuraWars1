#pragma once

#include "AbstractScene.h"

class IntermissionScene : public AbstractScene
{
public:
    const static char* ParameterTagStage;//パラメータのタグ「ステージ」
    const static char* ParameterTagLevel;//パラメータのタグ「レベル」

    IntermissionScene(IOnSceneChangedListener* impl, const Parameter& parameter);
    virtual ~IntermissionScene() = default;

    void update() override;
    void draw() const override;

private:

};

