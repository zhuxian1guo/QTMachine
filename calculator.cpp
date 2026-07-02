#include "calculator.h"
#include "qlineedit.h"
#include "ui_calculator.h"
#include <QGridLayout>
#include <QPushButton>
#include <QtMath>

// 递归计算四则运算字符串（不支持括号）
// 思路：先找低优先级运算符(+/-)拆分，再找高优先级(*/)
// - 和 / 必须用“全部拆分”以保证左结合；
// + 和 * 用“首次出现拆分 + 递归”即可（满足结合律）。
static double calculate(const QString &str)
{
    QString s = str.trimmed();
    if (s.isEmpty())
        return 0.0;

    // 处理前导正负号，例如 "-2+3"、"+5"
    bool negative = false;
    while (s.size() >= 1 && (s.at(0) == QLatin1Char('-') || s.at(0) == QLatin1Char('+'))) {
        // 仅当开头是符号、且字符串里还有其它运算符时才剥离，
        // 否则 "5" 或 "-" 这种交给 toDouble 处理
        bool hasOp = false;
        for (int i = 1; i < s.size(); ++i) {
            QChar c = s.at(i);
            if (c == QLatin1Char('+') || c == QLatin1Char('-') ||
                c == QLatin1Char('*') || c == QLatin1Char('/')) {
                hasOp = true;
                break;
            }
        }
        if (!hasOp)
            break;

        if (s.at(0) == QLatin1Char('-'))
            negative = !negative;
        s = s.mid(1);
    }

    // + ：首次出现拆分，右侧递归
    int idx = s.indexOf('+');
    if (idx > 0) {
        double v = calculate(s.left(idx)) + calculate(s.mid(idx + 1));
        return negative ? -v : v;
    }

    // - ：全部拆分，保证左结合 (2-3-4 => 2-3-4 而非 2-(3-4))
    idx = s.indexOf('-');
    if (idx > 0) {
        const QStringList list = s.split('-');
        double v = calculate(list[0]);
        for (int i = 1; i < list.count(); ++i)
            v -= calculate(list[i]);
        return negative ? -v : v;
    }

    // * ：全部拆分
    idx = s.indexOf('*');
    if (idx > 0) {
        const QStringList list = s.split('*');
        double v = calculate(list[0]);
        for (int i = 1; i < list.count(); ++i)
            v *= calculate(list[i]);
        return negative ? -v : v;
    }

    // / ：全部拆分，检查除零
    idx = s.indexOf('/');
    if (idx > 0) {
        const QStringList list = s.split('/');
        double v = calculate(list[0]);
        for (int i = 1; i < list.count(); ++i) {
            double d = calculate(list[i]);
            if (d == 0.0)
                return qQNaN();          // 除零返回 NaN，由调用方判断
            v /= d;
        }
        return negative ? -v : v;
    }

    // 纯数字
    bool ok = false;
    double val = s.toDouble(&ok);
    if (!ok)
        return qQNaN();                  // 非法表达式
    return negative ? -val : val;
}

// 把结果格式化成字符串：整数不带小数点，最多保留 12 位有效数字
static QString formatResult(double v)
{
    if (qIsNaN(v))
        return QStringLiteral("Error");
    if (qIsInf(v))
        return QStringLiteral("Infinity");
    // 整数结果直接显示为整数
    if (v == std::floor(v) && qAbs(v) < 1e15)
        return QString::number(static_cast<qint64>(v));
    return QString::number(v, 'g', 12);
}

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    this->setWindowTitle("Calculator");
    this->setFixedWidth(600);
    this->setFixedHeight(400);

    // 1. 创建网格布局对象
    QGridLayout *gridLayout = new QGridLayout(this);

    // 2. 设置布局的间距和边距
    gridLayout->setSpacing(10);
    gridLayout->setContentsMargins(10, 10, 10, 10);

    // 添加显示框
    QLineEdit *LE = new QLineEdit();
    LE->setReadOnly(true);
    LE->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    LE->setStyleSheet("font-size: 22px;");
    gridLayout->addWidget(LE, 0, 0, 1, 4);

    // 按钮文本，4 列网格
    const QStringList buttonsText = {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "0", ".", "=", "+",
        "C", "⌫"
    };

    // 把按钮加入布局并建立信号槽
    for (int i = 0; i < buttonsText.count(); ++i) {
        QPushButton *button = new QPushButton(buttonsText[i]);
        button->setFixedHeight(40);

        // 前 16 个填 4x4，最后两个(C / ⌫)放在第 5 行，各跨 2 列
        if (i < 16) {
            gridLayout->addWidget(button, 1 + i / 4, i % 4);
        } else {
            int col = (i - 16) * 2;      // 第 5 行：C 跨 0-1，⌫ 跨 2-3
            gridLayout->addWidget(button, 5, col, 1, 2);
        }

        const QString &text = buttonsText[i];

        if (text == "=") {
            QObject::connect(button, &QPushButton::clicked, [LE] {
                QString expression = LE->text();
                double result = calculate(expression);
                LE->setText(formatResult(result));
            });
        } else if (text == "C") {
            QObject::connect(button, &QPushButton::clicked, [LE] {
                LE->clear();
            });
        } else if (text == "⌫") {
            QObject::connect(button, &QPushButton::clicked, [LE] {
                LE->setText(LE->text().left(LE->text().length() - 1));
            });
        } else {
            QObject::connect(button, &QPushButton::clicked, [LE, text] {
                LE->setText(LE->text() + text);
            });
        }
    }

    this->setLayout(gridLayout);
}

Calculator::~Calculator()
{
    delete ui;
}
