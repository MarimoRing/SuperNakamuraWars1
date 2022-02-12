#include "ScenarioEndDemo.h"
#include "DxLib.h"
#include "Define.h"
#include "Keyboard.h"
#include "Pad.h"
#include "Intermission.h"
#include "Setting.h"

const char* ScenarioEndDemoScene::ParameterTagStage = "ParameterTagStage";//パラメータのタグ「ステージ」
const char* ScenarioEndDemoScene::ParameterTagLevel = "ParameterTagLevel";//パラメータのタグ「レベル」

ScenarioEndDemoScene::ScenarioEndDemoScene(IOnSceneChangedListener* impl, const Parameter& parameter) : AbstractScene(impl, parameter)
{
}

void ScenarioEndDemoScene::update()
{
    if (Pad::getIns()->get(ePad::decision) == 1) {
        Parameter parameter;
        parameter.set(IntermissionScene::ParameterTagLevel, Define::eLevel::Easy);
        const bool stackClear = false;
        _implSceneChanged->onSceneChanged(eScene::Intermission, parameter, stackClear);
        return;
    }
}

void ScenarioEndDemoScene::draw() const
{
    Color.Read();
    DrawBox(100, 100, 900, 900, Color.White, TRUE);
}
