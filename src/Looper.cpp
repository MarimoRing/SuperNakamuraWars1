#include "Looper.h"
#include "TitleScene.h"
#include "Error.h"
#include "ScenarioDemo.h"
#include "ScenarioEndDemo.h"
#include "Intermission.h"
#include "MapScene.h"
#include "Macro.h"
#include "Keyboard.h"
#include "Pad.h"
#include "Image.h"

using namespace std;

Looper::Looper()
{
    Image::getIns()->load();

    Parameter parameter;
    _sceneStack.push(make_shared<TitleScene>(this, parameter)); //タイトル画面シーンを作ってpush
}
/*!
@brief スタックのトップのシーンの処理をする
*/
bool Looper::loop()
{
    Keyboard::getIns()->update();   //キーボードの更新
    Pad::getIns()->update();        //ジョイパッドの更新
    _sceneStack.top()->update();    //スタックのトップのシーンを更新
    _sceneStack.top()->draw();      //スタックのトップのシーンを描画
    //_fps.draw();                    //FPSを表示
    _fps.wait();                    //設定したFPSになるように待機
    return true;
}

/*!
@brief シーン変更(各シーンからコールバックされる)
@param scene 変更するシーンのenum
@param parameter 前のシーンから引き継ぐパラメータ
@param stackClear 現在のシーンのスタックをクリアするか
*/
void Looper::onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear)
{
    if (stackClear) {//スタッククリアなら
        while (!_sceneStack.empty()) {//スタックを全部ポップする(スタックを空にする)
            _sceneStack.pop();
        }
    }
    switch (scene) {
    case Title://タイトル画面
        _sceneStack.push(make_shared<TitleScene>(this, parameter));
        break;
    case ScenarioDemo://タイトル画面
        _sceneStack.push(make_shared<ScenarioDemoScene>(this, parameter));
        break;
    case Map://マップ画面
        _sceneStack.push(make_shared<MapScene>(this, parameter));
        break;
    case Battle://戦闘画面
        break;
    case ScenarioEndDemo://タイトル画面
        _sceneStack.push(make_shared<ScenarioEndDemoScene>(this, parameter));
        break;
    case Intermission://インターミッション画面
        _sceneStack.push(make_shared<IntermissionScene>(this, parameter));
        break;
    default:
        //どうしようもないエラー発生
        ERR("あるはずのないシーンが呼ばれました");
        break;
    }
}
