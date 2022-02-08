#include "MapScene.h"
#include <DxLib.h>
#include "Macro.h"

const char* MapScene::ParameterTagStage = "ParameterTagStage";//�p�����[�^�̃^�O�u�X�e�[�W�v
const char* MapScene::ParameterTagLevel = "ParameterTagLevel";//�p�����[�^�̃^�O�u���x���v

MapScene::MapScene(IOnSceneChangedListener* impl, const Parameter& parameter) : AbstractScene(impl, parameter)
{
    _board = std::make_shared<Board>();
    _player = std::make_shared<Player>();
}

void MapScene::update()
{
    _board->update();
    _player->update();
}

void MapScene::draw() const
{
    _board->draw();
    _player->draw();
}
