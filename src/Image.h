#pragma once

#include "Singleton.h"
#include <vector>

class Image final : public Singleton<Image> {

public:
    Image();
    ~Image() = default;
    void load() {}
    void release();

    int getPlayer() const { return _player; }
    int getBoard() const { return _board; }
    int getBoard2() const { return _board2; }

private:
    int myLoadGraph(const char*);
    int myLoadDivGraph(char *fileName, int n, int xn, int yn, int w, int h, int* buf);

    std::vector<int> _images;
    int _player;
    int _board;
    int _board2;
};

