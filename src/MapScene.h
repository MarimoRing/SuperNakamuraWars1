
#pragma once

#include "AbstractScene.h"
#include "Player.h"
#include <memory>
#include "Board.h"

class MapScene : public AbstractScene
{
public:
    const static char* ParameterTagStage;//�p�����[�^�̃^�O�u�X�e�[�W�v
    const static char* ParameterTagLevel;//�p�����[�^�̃^�O�u���x���v

    MapScene(IOnSceneChangedListener* impl, const Parameter& parameter);
    virtual ~MapScene() = default;

    void update() override;
    void draw() const override;

private:
    std::shared_ptr<Player> _player;
    std::shared_ptr<Board>  _board;
};

