#include "MapScene.h"
#include "ScenarioEndDemo.h"
#include <DxLib.h>
#include "Macro.h"
#include "Keyboard.h"
#include "Pad.h"
#include "Define.h"

const char* MapScene::ParameterTagStage = "ParameterTagStage";//パラメータのタグ「ステージ」
const char* MapScene::ParameterTagLevel = "ParameterTagLevel";//パラメータのタグ「レベル」

MapScene::MapScene(IOnSceneChangedListener* impl, const Parameter& parameter) : AbstractScene(impl, parameter)
{
    _board = std::make_shared<Board>();
    _cursor = std::make_shared<Cursor>();
    _enemyManager = std::make_shared<EnemyManager>();
}

void MapScene::update()
{
    _board->update();
    _cursor->update();
    _enemyManager->update();
    if (Pad::getIns()->get(ePad::decision) == 1) {
        Parameter parameter;
        parameter.set(ScenarioEndDemoScene::ParameterTagLevel, Define::eLevel::Easy);
        const bool stackClear = false;
        _implSceneChanged->onSceneChanged(eScene::ScenarioEndDemo, parameter, stackClear);
        return;
    }
}

void MapScene::draw() const
{
    _board->draw();
    _cursor->draw();
    _enemyManager->draw();
}
