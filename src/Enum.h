#pragma once
//シーンの種類は "enum "で定義.
enum eScene {
    Title,  //タイトル画面
    ScenarioDemo, //シナリオデモ
    Map,   //マップ画面
    Battle, //戦闘画面
    ScenarioEndDemo, //シナリオエンドデモ
    Intermission, //インターミッション画面
};

enum MapState {
    Nothing,    //盤面上に何もない
    Friend,     //味方キャラクター
    Enemy,      //敵キャラクター
};
