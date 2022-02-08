
#pragma once

#include "AbstractScene.h"
#include "Cursor.h"
#include <memory>
#include "Board.h"
#include "EnemyManager.h"

class MapScene : public AbstractScene
{
public:
    const static char* ParameterTagStage;//パラメータのタグ「ステージ」
    const static char* ParameterTagLevel;//パラメータのタグ「レベル」

    MapScene(IOnSceneChangedListener* impl, const Parameter& parameter);
    virtual ~MapScene() = default;

    void update() override;
    void draw() const override;

private:
    std::shared_ptr<Cursor> _cursor;
    std::shared_ptr<Board>  _board;
    std::shared_ptr<EnemyManager>  _enemyManager;
};

