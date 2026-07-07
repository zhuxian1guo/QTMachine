#ifndef COMMON_H
#define COMMON_H

// common.h —— 项目级公共头(手动 #include 使用)
//
// 与 stable.h(PCH,自动注入)的分工:
//   - stable.h  : 自动注入每个 cpp,只放"极少变动"的 Qt/STL 大模块头
//   - common.h  : 手动 #include,放"项目相关、可能变动"的内容
//                 (项目宏、常量、工具函数声明、常用自定义类头)
//
// 注意:本文件不要加进 PRECOMPILED_HEADER。
//       变动频繁的头放进 PCH 会让整个工程每次都全量重编。

// ============================================================
// 1. 项目内常用自定义类头(按需增删,放最常用的几个即可,
//    不要把所有 formXX.h 都塞进来,否则改一个就拖慢一片)
// ============================================================
// #include "vip_mgr.h"
// #include "lottery.h"


// ============================================================
// 2. 通用宏
// ============================================================
// 消除"未使用变量/参数"警告
#ifndef UNUSED
#define UNUSED(x) (void)(x)
#endif

// 元素个数(C 数组用)
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#endif


// ============================================================
// 3. 全局常量(extern 声明,定义放某个 cpp)
// ============================================================
// extern const QString kAppVersion;
// extern const QString kDefaultLogPath;


// ============================================================
// 4. 全局工具函数声明(定义放 form13_logtype.cpp)
// ============================================================
// 自定义 printf 风格日志,写入 selfLog.log(工作目录)。
// 线程安全(内部加锁)。
// 使用前必须先调 customLogInit() 打开文件;程序结束调 customLogClose()。
void customLog(const char* format, ...);

// 打开日志文件 selfLog.log(追加模式)。成功返回 true。
// 应在 main() 开头调用一次,之后任何线程/文件均可调 customLog。
bool customLogInit();

// 关闭日志文件。可在 main() 结束前调用。
// 不调用也行——进程退出时由系统回收,但建议显式关闭以刷新缓冲。
void customLogClose();

#endif // COMMON_H
