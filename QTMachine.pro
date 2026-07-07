QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# 预编译头(PCH):编译稳定头一次,后续每个 cpp 复用,加速编译
# 注意:stable.h 不要加到下面 HEADERS 里,qmake 会自动处理
CONFIG += precompile_header
PRECOMPILED_HEADER = stable.h

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculator.cpp \
    countdown.cpp \
    form10_dlldev.cpp \
    form11_client.cpp \
    form11_server.cpp \
    form12_textedit.cpp \
    form13_logtype.cpp \
    form14_vipconsum.cpp \
    form6_draw.cpp \
    form8_opencv.cpp \
    form9_serialiodesign.cpp \
    lottery.cpp \
    main.cpp \
    mainwindow.cpp \
    testextern.cpp \
    vip_mgr.cpp

HEADERS += \
    calculator.h \
    countdown.h \
    form10_dlldev.h \
    form11_client.h \
    form11_server.h \
    form12_textedit.h \
    form13_logtype.h \
    form14_vipconsum.h \
    form6_draw.h \
    form8_opencv.h \
    form9_serialiodesign.h \
    lottery.h \
    mainwindow.h \
    testextern.h \
    vip_mgr.h \
    common.h

FORMS += \
    calculator.ui \
    countdown.ui \
    form10_dlldev.ui \
    form11_client.ui \
    form11_server.ui \
    form12_textedit.ui \
    form13_logtype.ui \
    form14_vipconsum.ui \
    form6_draw.ui \
    form8_opencv.ui \
    form9_serialiodesign.ui \
    lottery.ui \
    mainwindow.ui \
    vip_mgr.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


#头文件路径包含
INCLUDEPATH += "D:/WorkSpace/Study/QT/QTGit/QTMachine/DLLDev/include"
LIBS += -L"D:/WorkSpace/Study/QT/QTGit/QTMachine/DLLDev/lib" -lDLLDev



# ---- OpenCV 配置（仅 MSVC 套件下生效；MinGW 套件会忽略）----
# 用 Qt 5.15.2 msvc2019_64 套件构建；OpenCV 用官方 Windows 预编译包（x64/vc16 = VS2019）
msvc {
    # 源文件是 UTF-8（含中文注释），MSVC 默认按 GBK 读会报错，强制按 UTF-8 解析
    QMAKE_CXXFLAGS += /utf-8

    # 改成你解压 OpenCV 后的 build 目录（里面要有 include/ 和 x64/）
    OPENCV_DIR = C:/opencv/build
    INCLUDEPATH += "$$OPENCV_DIR/include"
    LIBS += -L"$$OPENCV_DIR/x64/vc16/lib/"
    # OpenCV 4.12.0 → opencv_world4120（release）/ opencv_world4120d（debug）
    CONFIG(debug, release|debug) {
        LIBS += -lopencv_world4120d
    } else {
        LIBS += -lopencv_world4120
    }
}
