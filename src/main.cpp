#include <DxLib.h>
#include "SystemMain.h"

//DXライブラリの面倒な処理は「SystemMain」で行っています。
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
    SystemMain system;
    if (system.initialize()) {
        system.main();
    }
    system.finalize();
}
