#include "Intermission.h"
#include "DxLib.h"
#include "Define.h"
#include "Keyboard.h"
#include "Pad.h"
#include "ScenarioDemo.h"
#include "Setting.h"

const char* IntermissionScene::ParameterTagStage = "ParameterTagStage";//パラメータのタグ「ステージ」
const char* IntermissionScene::ParameterTagLevel = "ParameterTagLevel";//パラメータのタグ「レベル」

IntermissionScene::IntermissionScene(IOnSceneChangedListener* impl, const Parameter& parameter) : AbstractScene(impl, parameter)
{
}

void IntermissionScene::update()
{
    if (Pad::getIns()->get(ePad::decision) == 1) {
        Parameter parameter;
        parameter.set(ScenarioDemoScene::ParameterTagLevel, Define::eLevel::Easy);
        const bool stackClear = false;
        _implSceneChanged->onSceneChanged(eScene::ScenarioDemo, parameter, stackClear);
        return;
    }
}

void IntermissionScene::draw() const
{
    Color.Read();
    DrawBox(100, 100, 900, 900, Color.Blue, TRUE);
}
