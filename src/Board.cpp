#include "Board.h"
#include "Define.h"
#include <DxLib.h>
#include "Image.h"

bool Board::update()
{
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
    int color = GetColor(255, 255, 255);
    const int x = Define::IN_X;
    const int y = Define::IN_Y;
    const int w = Define::IN_W;
    const int h = Define::IN_H;
    for (int i = 0; i <= w + 100; i += 100) {
        for (int j = 0; j <= h + 100; j += 100) {
            DrawLine(i, 0, i, j, color);
            DrawLine(0, j, i, j, color);
        }
    }
}
