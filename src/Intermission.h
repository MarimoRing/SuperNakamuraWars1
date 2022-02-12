#pragma once

#include "AbstractScene.h"

class IntermissionScene : public AbstractScene
{
public:
    const static char* ParameterTagStage;//�p�����[�^�̃^�O�u�X�e�[�W�v
    const static char* ParameterTagLevel;//�p�����[�^�̃^�O�u���x���v

    IntermissionScene(IOnSceneChangedListener* impl, const Parameter& parameter);
    virtual ~IntermissionScene() = default;

    void update() override;
    void draw() const override;

private:

};

