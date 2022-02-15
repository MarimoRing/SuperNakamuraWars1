#include "TitleScene.h"
#include <DxLib.h>
#include "ScenarioDemo.h"
#include "Define.h"
#include "Keyboard.h"
#include "Pad.h"
#include "Setting.h"

TitleScene::TitleScene(IOnSceneChangedListener* impl, const Parameter& parameter) : AbstractScene(impl, parameter)
{
    Font.Read();
    int FontSize = CreateFontToHandle(NULL, 30, 6);

}

void TitleScene::update()
{
    if (Pad::getIns()->get(ePad::up) == 1) {
        if (X > 0) X -= 100;
        else if (X == 0) X = 400; 
        return;
    }
    if (Pad::getIns()->get(ePad::down) == 1) {
        if (X < 400) X += 100;
        else if (X == 400) X = 0;
        return;
    }
    if (Pad::getIns()->get(ePad::decision) == 1) {
        if (X == 0) {
            Parameter parameter;
            parameter.set(ScenarioDemoScene::ParameterTagLevel, Define::eLevel::Easy);
            const bool stackClear = false;
            _implSceneChanged->onSceneChanged(eScene::ScenarioDemo, parameter, stackClear);
            return;
        }
    }
}

void TitleScene::draw() const
{
    const static int A = 400;
    const static int B = 400;
    const static int I = 38;

    Color.Read();
    DrawStringToHandle(100, 100, "�X�[�p�[��������", Color.White, Font.c[38]);
    DrawBox(A - 150, B - 50, A + 600, B + 520, Color.Blue, TRUE);
    DrawStringToHandle(A, B, "�X�^�[�g", Color.White, Font.c[I]);
    DrawStringToHandle(A, B + 100, "���[�h", Color.White, Font.c[I]);
    DrawStringToHandle(A, B + 200, "�R���e�B�j���[", Color.White, Font.c[I]);
    DrawStringToHandle(A, B + 300, "���j���[", Color.White, Font.c[I]);
    DrawStringToHandle(A, B + 400, "�Q�[���I��", Color.White, Font.c[I]);
    DrawStringToHandle(A - 100, B + X, "��", Color.White, Font.c[I]);
}
