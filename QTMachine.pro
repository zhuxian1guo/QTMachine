QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculator.cpp \
    countdown.cpp \
    form6_draw.cpp \
    form8_opencv.cpp \
    lottery.cpp \
    main.cpp \
    mainwindow.cpp \
    testextern.cpp \
    vip_mgr.cpp

HEADERS += \
    calculator.h \
    countdown.h \
    form6_draw.h \
    form8_opencv.h \
    lottery.h \
    mainwindow.h \
    testextern.h \
    vip_mgr.h

FORMS += \
    calculator.ui \
    countdown.ui \
    form6_draw.ui \
    form8_opencv.ui \
    lottery.ui \
    mainwindow.ui \
    vip_mgr.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

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
