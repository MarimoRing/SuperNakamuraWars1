#include "TitleScene.h"
#include <DxLib.h>
#include "GameScene.h"
#include "Define.h"
#include "Keyboard.h"
#include "Pad.h"
#include "Setting.h"
#include "Picture.h"
#include "Action.h"

TitleScene::TitleScene(IOnSceneChangedListener* impl, const Parameter& parameter) : AbstractScene(impl, parameter)
{
}

void TitleScene::update()
{
    if (Pad::getIns()->get(ePad::up) == 1) {
        if (X > 0) X -= 100;
        else if (X == 0) X = 300; 
        return;
    }
    if (Pad::getIns()->get(ePad::down) == 1) {
        if (X < 300) X += 100;
        else if (X == 300) X = 0;
        return;
    }
    if (Pad::getIns()->get(ePad::decision) == 1) {
        if (X == 0) {
            Parameter parameter;
            parameter.set(GameScene::ParameterTagLevel, Define::eLevel::Easy);
            const bool stackClear = false;
            _implSceneChanged->onSceneChanged(eScene::Game, parameter, stackClear);
            return;
        }
    }
}

void TitleScene::draw() const
{
    const static int A = 400;
    const static int B = 400;

    Color.Read();
    DrawString(100, 100, "スーパー中村卓大戦", Color.White/*GetColor(255, 255, 255)*/);
    DrawBox(A - 150, B - 50, A + 400, B + 420, Color.Blue, TRUE);
    DrawString(A, B, "New Game", Color.White);
    DrawString(A, B + 100, "Continue", Color.White);
    DrawString(A, B + 200, "Option", Color.White);
    DrawString(A, B + 300, "Exit", Color.White);
    DrawString(A - 100, B + X, "→", Color.White);    
}
