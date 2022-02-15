#include "Board.h"
#include "Define.h"
#include <DxLib.h>
#include "Image.h"
#include "Setting.h"

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