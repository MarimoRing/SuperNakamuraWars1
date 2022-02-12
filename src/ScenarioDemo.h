
#pragma once

#include "AbstractScene.h"

class ScenarioDemoScene : public AbstractScene
{
public:
    const static char* ParameterTagStage;//パラメータのタグ「ステージ」
    const static char* ParameterTagLevel;//パラメータのタグ「レベル」

    ScenarioDemoScene(IOnSceneChangedListener* impl, const Parameter& parameter);
    virtual ~ScenarioDemoScene() = default;

    void update() override;
    void draw() const override;

private:

};

