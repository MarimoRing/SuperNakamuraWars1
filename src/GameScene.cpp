#include "GameScene.h"
#include <DxLib.h>
#include "Macro.h"

const char* GameScene::ParameterTagStage = "ParameterTagStage";//パラメータのタグ「ステージ」
const char* GameScene::ParameterTagLevel = "ParameterTagLevel";//パラメータのタグ「レベル」

GameScene::GameScene(IOnSceneChangedListener* impl, const Parameter& parameter) : AbstractScene(impl, parameter)
{
    _player = std::make_shared<Player>();
}

void GameScene::update()
{
    _player->update();
}

void GameScene::draw() const
{
    _player->draw();
}
