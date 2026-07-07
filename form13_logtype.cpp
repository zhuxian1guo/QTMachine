#include "form13_logtype.h"
#include "ui_form13_logtype.h"
#include "common.h"
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include <QMutex>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <string>

// 文件级句柄,加 static 限定在本翻译单元(避免污染全局符号)
static FILE* selfLogFile = nullptr;
// 多线程安全(如果确定单线程,可删)
static QMutex logMutex;

Form13_LogType::Form13_LogType(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form13_LogType)
{
    ui->setupUi(this);

    // 日志文件已由 customLogInit() 在 main() 中打开,这里只做示例输出。
    // 若担心未初始化,可解除下面两行(会安全忽略重复打开)。
    // customLogInit();
    for (int i = 0; i < 5; ++i) {
        customLog("Debug: Iteration %d", i);
    }
}

Form13_LogType::~Form13_LogType()
{
    // 不在这里关闭日志文件——文件生命周期归整个程序所有,
    // 由 customLogClose() / 进程退出负责关闭。
    delete ui;
}



//拦截各类IDE消息 保存到LOG文本
void customMessageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
    QString logMessage;

    switch (type) {
    case QtDebugMsg:
        logMessage = QString("Debug: %1").arg(msg);
        break;

    case QtInfoMsg:
        logMessage = QString("Info: %1").arg(msg);
        break;

    case QtWarningMsg:
        logMessage = QString("Warning: %1").arg(msg);
        break;

    case QtCriticalMsg:
        logMessage = QString("Critical: %1").arg(msg);
        break;

    case QtFatalMsg:
        logMessage = QString("Fatal: %1").arg(msg);
        break;

    default:
        break;
    }

    QFile logFile("application.log");
    if (logFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream logStream(&logFile);
        logStream << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ") << logMessage ;
        logFile.close();
    }
}


// 打开日志文件(追加模式)。重复调用安全——已打开则忽略,直接返回 true。
bool customLogInit()
{
    if (selfLogFile != nullptr) {
        return true;   // 已打开,避免重复打开造成句柄泄漏
    }
    selfLogFile = fopen("selfLog.log", "a");
    return selfLogFile != nullptr;
}

// 关闭日志文件。重复调用安全——未打开则跳过。
void customLogClose()
{
    if (selfLogFile != nullptr) {
        fflush(selfLogFile);
        fclose(selfLogFile);
        selfLogFile = nullptr;
    }
}

//自定义函数
void customLog(const char* format, ...)
{
    if (selfLogFile == nullptr) {
        return;
    }

    // 1. 时间戳 —— 线程安全用 localtime_s (MSVC)
    time_t rawtime = time(nullptr);
    struct tm timeinfo;
    char timeBuffer[32] = "?";
    if (localtime_s(&timeinfo, &rawtime) == 0) {
        strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", &timeinfo);
    }

    // 2. 格式化消息 —— 先算长度,再按需分配,避免静默截断
    va_list args;
    va_start(args, format);
    va_list argsCopy;
    va_copy(argsCopy, args);
    int needed = vsnprintf(nullptr, 0, format, argsCopy);
    va_end(argsCopy);

    std::string message;
    if (needed > 0) {
        message.resize(needed + 1);
        vsnprintf(&message[0], message.size(), format, args);
        message.resize(needed);          // 去掉末尾 '\0'
    }
    va_end(args);

    // 3. 写文件 —— 加锁,防多线程交错
    QMutexLocker locker(&logMutex);
    fprintf(selfLogFile, "[%s] %s\n", timeBuffer, message.c_str());
    fflush(selfLogFile);
}


// int WriteLog(QString iType, QString istr)
// {
//     glockLog.lock();
//     QDateTime time1 = QDateTime::currentDateTime();//获取系统现在的时间
//     QString lstrTime = time1.toString("yyyy-MM-dd hh:mm:ss.zzz"); //设置显示格式
//     QString lstrDate= time1.toString("yyyyMMdd"); //设置显示格式
//     QString lstrMonth=lstrDate.mid(0,6); //设置显示格式
//     QString lstrPath=GlobalConstPara.APPPath+"logs/Power_"+lstrMonth+"/";
// // QString lstrPath= "/logs/Power_"+lstrMonth+"/";
//     QString fileName = lstrPath+iType+"_"+lstrDate+".log";
//     QString lstrData = "【"+lstrTime+"】"+istr;
//     QDir my_dir;
//     if (! (my_dir.exists(lstrPath)))
//     {
//         my_dir.mkpath(lstrPath);
//     }
//     QFile f(fileName);
//     f.open(QIODevice::WriteOnly|QIODevice::Append) ;
// //    QTextStream t(&f);
// //    t << lstrData<< endl;
// //    f.close();
//     QTextStream ts(&f);
//     ts.setGenerateByteOrderMark(true);    //这句是重点
//     ts.setCodec("UTF-8");
//     ts << lstrData<< endl;
//     f.close();
//     glockLog.unlock();
//     return 0;
// }
