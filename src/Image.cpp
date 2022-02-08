#include "Image.h"
#include <DxLib.h>

Image::Image()
{
    _player = myLoadGraph("./data/image/cursor/cursor.png");
    _board = myLoadGraph("./data/image/board/board2.png");
    _board2 = myLoadGraph("./data/image/board/universe.png");
    myLoadDivGraph("./data/image/enemy/normal.png", 9, 3, 3, 54, 54, _enemyNormal);
    myLoadDivGraph("./data/image/enemy/bit.png", 9, 3, 3, 160, 120, _enemyBig);
    myLoadDivGraph("./data/image/enemy/small.png", 2, 2, 1, 32, 32, _enemySmall);
}

/*!
@brief 今までロードした画像を解放する
*/
void Image::release() 
{
    const int size = _images.size();
    for (int i = 0; i < size; i++) {
        DeleteGraph(_images[i]);
    }
    _images.clear();
}

/*!
@brief LoadGraphをして、かつそのハンドルをメンバ変数に追加する
*/
int Image::myLoadGraph(const char *fileName)
{
    int ret = LoadGraph(fileName);
    _images.push_back(ret);
    return ret;
}

/*!
@brief LoadDivGraphをして、かつそのハンドルをメンバ変数に追加する
*/
int Image::myLoadDivGraph(const char *fileName, int n, int xn, int yn, int w, int h, int* buf)
{
    int ret = LoadDivGraph(fileName, n, xn, yn, w, h, buf);
    for (int i = 0; i < n; i++) {
        _images.push_back(buf[i]);
    }
    return ret;
}