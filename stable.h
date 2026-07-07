#ifndef STABLE_H
#define STABLE_H

// 预编译头(PCH)
// 这里只放"稳定少变"的头文件。修改本文件会触发整个工程全量重编,
// 所以不要把频繁变动的项目头(formXX.h 等)放进来,只放 Qt 模块头 / STL 头。
//
// 配合 .pro 里的:
//     CONFIG += precompile_header
//     PRECOMPILED_HEADER = stable.h
// qmake 会自动把本头编译成 .pch 并注入每个 cpp,源文件无需手动 #include "stable.h"。
// 想加新模块:先在 .pro 的 QT += 加模块,再在这里加对应大模块头即可。

// --- Qt 模块大头(对应 .pro 里 QT += 的模块)---
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QtSql>

// --- 常用 STL ---
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdarg>

#endif // STABLE_H
