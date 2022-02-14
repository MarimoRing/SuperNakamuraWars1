#include "Board.h"
#include "Define.h"
#include <DxLib.h>
#include "Image.h"
#include "Setting.h"
#include "Enum.h"

bool Board::update()
{
    mapState();
    return true;
}

void Board::draw() const
{
    DrawGraph(Define::OUT_W, 0, Image::getIns()->getBoard(), TRUE);
    DrawGraph(            0, 0, Image::getIns()->getBoard2(), TRUE);
    drawFrame();
}

void Board::drawFrame() const
{
    Color.Read();
    const int w = Define::OUT_W;
    const int h = Define::OUT_H;
    for (int i = 0; i <= w; i += 100) {
        for (int j = 0; j <= h; j += 100) {
            DrawLine(i, 0, i, j, Color.White);
            DrawLine(0, j, i, j, Color.White);
        }
    }
}

/*!
@brief マップ上でキャラクターの有無と敵味方を判断する
*/
void Board::mapState()
{
    const static int w = Define::OUT_W / 100;
    const static int h = Define::OUT_H / 100;
    int mapState[9][9];
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            mapState[i][j] = Nothing;
            //if () mapState[i][j] = Friend;
            //if () mapState[i][j] = Enemy;
        }
    }
}