#include <DxLib.h>
#include "SystemMain.h"

//DX���C�u�����̖ʓ|�ȏ����́uSystemMain�v�ōs���Ă��܂��B
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
    SystemMain system;
    if (system.initialize()) {
        system.main();
    }
    system.finalize();
}
