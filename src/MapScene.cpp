#include "MapScene.h"
#include <DxLib.h>
#include "Macro.h"

const char* MapScene::ParameterTagStage = "ParameterTagStage";//パラメータのタグ「ステージ」
const char* MapScene::ParameterTagLevel = "ParameterTagLevel";//パラメータのタグ「レベル」

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
