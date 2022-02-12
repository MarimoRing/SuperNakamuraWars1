#include "ScenarioDemo.h"
#include "DxLib.h"
#include "Define.h"
#include "Keyboard.h"
#include "Pad.h"
#include "MapScene.h"
#include "Setting.h"

const char* ScenarioDemoScene::ParameterTagStage = "ParameterTagStage";//パラメータのタグ「ステージ」
const char* ScenarioDemoScene::ParameterTagLevel = "ParameterTagLevel";//パラメータのタグ「レベル」

ScenarioDemoScene::ScenarioDemoScene(IOnSceneChangedListener* impl, const Parameter& parameter) : AbstractScene(impl, parameter)
{
}

void ScenarioDemoScene::update()
{
    if (Pad::getIns()->get(ePad::decision) == 1) {
        Parameter parameter;
        parameter.set(MapScene::ParameterTagLevel, Define::eLevel::Easy);
        const bool stackClear = false;
        _implSceneChanged->onSceneChanged(eScene::Map, parameter, stackClear);
        return;
    }
}

void ScenarioDemoScene::draw() const
{
    Color.Read();
    DrawBox(100, 100, 800, 800, Color.White, TRUE);
}
