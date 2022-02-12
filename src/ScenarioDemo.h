
#pragma once

#include "AbstractScene.h"

class ScenarioDemoScene : public AbstractScene
{
public:
    const static char* ParameterTagStage;//�p�����[�^�̃^�O�u�X�e�[�W�v
    const static char* ParameterTagLevel;//�p�����[�^�̃^�O�u���x���v

    ScenarioDemoScene(IOnSceneChangedListener* impl, const Parameter& parameter);
    virtual ~ScenarioDemoScene() = default;

    void update() override;
    void draw() const override;

private:

};

