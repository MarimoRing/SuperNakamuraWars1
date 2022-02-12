#pragma once

#include "AbstractScene.h"

class ScenarioEndDemoScene : public AbstractScene
{
public:
    const static char* ParameterTagStage;//パラメータのタグ「ステージ」
    const static char* ParameterTagLevel;//パラメータのタグ「レベル」

    ScenarioEndDemoScene(IOnSceneChangedListener* impl, const Parameter& parameter);
    virtual ~ScenarioEndDemoScene() = default;

    void update() override;
    void draw() const override;

private:

};

