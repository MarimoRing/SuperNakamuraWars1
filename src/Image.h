#pragma once

#include "Singleton.h"
#include <vector>
#include <array>

class Image final : public Singleton<Image> {

public:
    Image();
    ~Image() = default;
    void load() {}
    void release();

    int getCursor() const { return _player; }
    int getBoard()  const { return _board; }
    int getBoard2() const { return _board2; }
    const int* getEnemySmall () const { return _enemySmall; }
    const int* getEnemyNormal() const { return _enemyNormal; }
    const int* getEnemyBig   () const { return _enemyBig; }

private:
    int myLoadGraph(const char*);
    int myLoadDivGraph(const char *fileName, int n, int xn, int yn, int w, int h, int* buf);

    std::vector<int> _images;
    int _player;
    int _board;
    int _board2;
    int _enemySmall[2];
    int _enemyNormal[9];
    int _enemyBig[9];

};

