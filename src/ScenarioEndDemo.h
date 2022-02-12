#pragma once

#include "AbstractScene.h"

class ScenarioEndDemoScene : public AbstractScene
{
public:
    const static char* ParameterTagStage;//�p�����[�^�̃^�O�u�X�e�[�W�v
    const static char* ParameterTagLevel;//�p�����[�^�̃^�O�u���x���v

    ScenarioEndDemoScene(IOnSceneChangedListener* impl, const Parameter& parameter);
    virtual ~ScenarioEndDemoScene() = default;

    void update() override;
    void draw() const override;

private:

};

