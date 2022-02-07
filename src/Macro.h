#pragma once

#include "Error.h"
//#include "windows.h"
#include "DxLib.h"

#define ERR(str) Error::finish(str,_T(__FUNCTION__),__LINE__)
