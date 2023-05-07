#include "calculator.h"
#include <QMessageBox>
#include "operate.h"
#include <bitset>
//#pragma execution_character_set("utf-8")

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    initCalculator();

    (void)connect(ui.num0, &QPushButton::clicked, this, &Calculator::num0Clicked);
    (void)connect(ui.num1, &QPushButton::clicked, this, &Calculator::num1Clicked);
    (void)connect(ui.num2, &QPushButton::clicked, this, &Calculator::num2Clicked);
    (void)connect(ui.num3, &QPushButton::clicked, this, &Calculator::num3Clicked);
    (void)connect(ui.num4, &QPushButton::clicked, this, &Calculator::num4Clicked);
    (void)connect(ui.num5, &QPushButton::clicked, this, &Calculator::num5Clicked);
    (void)connect(ui.num6, &QPushButton::clicked, this, &Calculator::num6Clicked);
    (void)connect(ui.num7, &QPushButton::clicked, this, &Calculator::num7Clicked);
    (void)connect(ui.num8, &QPushButton::clicked, this, &Calculator::num8Clicked);
    (void)connect(ui.num9, &QPushButton::clicked, this, &Calculator::num9Clicked);
    (void)connect(ui.btnAllClear, &QPushButton::clicked, this, &Calculator::btnAllClearClicked);
    (void)connect(ui.btnClearLine, &QPushButton::clicked, this, &Calculator::btnClearLineClicked);
    (void)connect(ui.btnDel, &QPushButton::clicked, this, &Calculator::btnDelClicked);
    (void)connect(ui.btnAdd, &QPushButton::clicked, this, &Calculator::btnAddClicked);
    (void)connect(ui.btnSubtract, &QPushButton::clicked, this, &Calculator::btnSubtractClicked);
    (void)connect(ui.btnMultiply, &QPushButton::clicked, this, &Calculator::btnMultiplyClicked);
    (void)connect(ui.btnDivide, &QPushButton::clicked, this, &Calculator::btnDivideClicked);
    (void)connect(ui.btnEqual, &QPushButton::clicked, this, &Calculator::btnEqualClicked);
    (void)connect(ui.btnDot, &QPushButton::clicked, this, &Calculator::btnDotClicked);
    (void)connect(ui.btnLeftBracket, &QPushButton::clicked, this, &Calculator::btnLeftBracketClicked);
    (void)connect(ui.btnRightBracket, &QPushButton::clicked, this, &Calculator::btnRightBracketClicked);
    (void)connect(ui.btn10to2, &QPushButton::clicked, this, &Calculator::btn10to2Clicked);
    (void)connect(ui.btnSquare, &QPushButton::clicked, this, &Calculator::btnSquareClicked);
    (void)connect(ui.btnSqrt, &QPushButton::clicked, this, &Calculator::btnSqrtClicked);
    (void)connect(ui.btnMod, &QPushButton::clicked, this, &Calculator::btnModClicked);
}

Calculator::~Calculator()
{}

void Calculator::initCalculator()   //初始化计算器
{
    this->setWindowTitle("calculator");
    ui.lineEdit->setReadOnly(true); //输入框不可编辑，只能通过按键输入
    ui.lcdNumber->display("0"); //初始显示0
}

void Calculator::num0Clicked()      //输入数字0-9
{
    currentInputNumbers += "0";
    ui.lcdNumber->display(currentInputNumbers);
    expression += "0";
    ui.lineEdit->setText(expression);
}

void Calculator::num1Clicked()
{
    currentInputNumbers += "1";
    ui.lcdNumber->display(currentInputNumbers);
    expression += "1";
    ui.lineEdit->setText(expression);
}

void Calculator::num2Clicked()
{
    currentInputNumbers += "2";
    ui.lcdNumber->display(currentInputNumbers);
    expression += "2";
    ui.lineEdit->setText(expression);
}

void Calculator::num3Clicked()
{
    currentInputNumbers += "3";
    ui.lcdNumber->display(currentInputNumbers);
    expression += "3";
    ui.lineEdit->setText(expression);
}

void Calculator::num4Clicked()
{
    currentInputNumbers += "4";
    ui.lcdNumber->display(currentInputNumbers);
    expression += "4";
    ui.lineEdit->setText(expression);
}

void Calculator::num5Clicked()
{
    currentInputNumbers += "5";
    ui.lcdNumber->display(currentInputNumbers);
    expression += "5";
    ui.lineEdit->setText(expression);
}

void Calculator::num6Clicked()
{
    currentInputNumbers += "6";
    ui.lcdNumber->display(currentInputNumbers);
    expression += "6";
    ui.lineEdit->setText(expression);
}

void Calculator::num7Clicked()
{
    currentInputNumbers += "7";
    ui.lcdNumber->display(currentInputNumbers);
    expression += "7";
    ui.lineEdit->setText(expression);
}

void Calculator::num8Clicked()
{
    currentInputNumbers += "8";
    ui.lcdNumber->display(currentInputNumbers);
    expression += "8";
    ui.lineEdit->setText(expression);
}

void Calculator::num9Clicked()
{
    currentInputNumbers += "9";
    ui.lcdNumber->display(currentInputNumbers);
    expression += "9";
    ui.lineEdit->setText(expression);
}

void Calculator::btnAllClearClicked()       //清空表达式
{
    expression.clear();
    ui.lineEdit->setText(expression);
    currentInputNumbers.clear();
    ui.lcdNumber->display(currentInputNumbers);
    bracketStack.clear();
}

void Calculator::btnClearLineClicked()       //清空当前输入的整个数值
{
    expression.chop(currentInputNumbers.size());
    ui.lineEdit->setText(expression);
    currentInputNumbers.clear();
    ui.lcdNumber->display(currentInputNumbers);
}

void Calculator::btnDelClicked()            //清除一个输入
{
    expression.chop(1);
    ui.lineEdit->setText(expression);
    currentInputNumbers.chop(1);
    ui.lcdNumber->display(currentInputNumbers);
    if (expression.at(expression.length() - 1) == '(')          //如果清除的是括号，额外考虑
    {
        bracketStack.pop();
    }
    if (expression.at(expression.length() - 1) == ')')
    {
        bracketStack.push('(');
    }
}

void Calculator::btnAddClicked()            //加
{
    if (expression.isEmpty())return;
    QString operators = "+-*/(";             //记录运算符，用来做校验对比
    if (operators.contains(expression.at(expression.length() - 1)))
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("不能连续输入运算符"));
        return;
    }
    currentInputNumbers.clear();
    expression += "+";
    ui.lineEdit->setText(expression);
}

void Calculator::btnSubtractClicked()       //减
{
    if (expression.isEmpty())return;
    QString operators = "+-*/(";             //记录运算符，用来做校验对比
    if (operators.contains(expression.at(expression.length() - 1)))
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("不能连续输入运算符"));
        return;
    }
    currentInputNumbers.clear();
    expression += "-";
    ui.lineEdit->setText(expression);
}

void Calculator::btnMultiplyClicked()       //乘
{
    if (expression.isEmpty())return;
    QString operators = "+-*/(";             //记录运算符，用来做校验对比
    if (operators.contains(expression.at(expression.length() - 1)))
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("不能连续输入运算符"));
        return;
    }
    currentInputNumbers.clear();
    expression += "*";
    ui.lineEdit->setText(expression);
}

void Calculator::btnDivideClicked()         //除
{
    if (expression.isEmpty())return;
    QString operators = "+-*/(";             //记录运算符，用来做校验对比
    if (operators.contains(expression.at(expression.length() - 1)))
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("不能连续输入运算符"));
        return;
    }
    currentInputNumbers.clear();
    expression += "/";
    ui.lineEdit->setText(expression);
}

void Calculator::btnEqualClicked()      //等号计算
{
    if (expression.isEmpty())return;

    currentInputNumbers.clear();

    //检查输入格式规范：除数不能为0，括号的结合匹配，表达式不能以运算符结尾等等的判断
    if (verifyInput() == false) return;

    std::string rpn = toRPN(expression.toStdString()); // 中缀表达式转为逆波兰表达式
    string resultString = to_string(calculateRPN(rpn));// 计算逆波兰表达式的值，转换成string
    resultString= resultString.substr(0, resultString.find_last_not_of('0') + 1);//去掉double转string生成的尾随0
    if (resultString.back() == '.') resultString.pop_back();//去掉末尾小数点
        
    QString resultQString = QString::fromStdString(resultString); //string转QString
    
    expression += "=" + resultQString;
    ui.lcdNumber->display(resultQString);
    ui.lineEdit->setText(expression);

    currentInputNumbers.clear();
    expression.clear();

}

void Calculator::btnDotClicked()        //小数点输入
{
    if (currentInputNumbers.isEmpty())return;                     //小数点前没有数值时不可输入小数点
    if (currentInputNumbers.lastIndexOf('.') != -1)return;      //输入一个数值时，不可多次输入小数点
    expression += ".";
    currentInputNumbers += ".";
    ui.lcdNumber->display(currentInputNumbers);
    ui.lineEdit->setText(expression);
    return;

}

void Calculator::btnLeftBracketClicked()    //左括号
{
    QString operators = "+-*/";             //记录运算符，用来做校验对比
    if (operators.contains(expression.at(expression.length() - 1)))
    {
        currentInputNumbers.clear();
        expression += "(";
        bracketStack.push('(');
        ui.lineEdit->setText(expression);
    }
    return;
}

void Calculator::btnRightBracketClicked()       //右括号
{
    QString operators = "+-*/(";             //记录运算符，用来做校验对比
    if (operators.contains(expression.at(expression.length() - 1)))    return;
    if (bracketStack.empty())return;            //如果没有左括号，则不能输入右括号
    bracketStack.pop();                         //每输入一个右括号，匹配一个左括号
    currentInputNumbers.clear();
    expression += ")";
    ui.lineEdit->setText(expression);
    return;
}

void Calculator::btn10to2Clicked()     //十进制转二进制
{
    bool isAllDigit;
    int result = expression.toInt(&isAllDigit);
    if (isAllDigit)
    {
        std::bitset<sizeof(result) * 8> binary(result);
        QString resultString = QString::fromStdString(binary.to_string());
        ui.lcdNumber->display(resultString);
    }
    else QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("进制转换时，表达式应只包整数"));
    return;
}

void Calculator::btnSquareClicked()     //平方
{
    bool isAllDigit;
    double result=expression.toDouble(&isAllDigit);
    if (isAllDigit)
    {
        ui.lcdNumber->display(result* result);
    }   
    else QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("计算平方时，表达式应只包含数值"));
    return;
}

void Calculator::btnSqrtClicked()       //开方
{
    bool isAllDigit;
    double result = expression.toDouble(&isAllDigit);
    if (isAllDigit)
    {
        ui.lcdNumber->display(sqrt(result));
    }
    else QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("计算开方时，表达式应只包含数值"));
    return;
}

void Calculator::btnModClicked()        //求余
{
    if (expression.contains('%'))
    {
        QStringList parts = expression.split('%'); // 以'%'为分隔符
        QString part1 = parts[0]; // 获取分割后的第一个子串
        QString part2 = parts[1]; // 获取分割后的第二个子串
        bool isAllDigit_1, isAllDigit_2;
        int num1 = part1.toInt(&isAllDigit_1);
        int num2 = part2.toInt(&isAllDigit_2);
        if (isAllDigit_1 && isAllDigit_2)
        {
            ui.lcdNumber->display(num1 % num2);
        }
        else QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("计算求余时，表达式格式应为“a%b”"));
        return;
    }
    else
    {
        currentInputNumbers.clear();
        expression += "%";
        ui.lineEdit->setText(expression);
        return;
    }

}

bool Calculator::verifyInput()          
{   //检查输入格式规范：除数不能为0，括号的结合匹配，表达式不能以运算符结尾等等的判断

    //除数为零判断
    QList<int> indexList;

    int index = expression.indexOf('/');
    while (index >= 0)
    {
        indexList.append(index);
        index = expression.indexOf('/', index + 1);
    }

    // 对每个‘/’进行判断
    for (int i = 0; i < indexList.size(); ++i)
    {
        if (expression[indexList.at(i) + 1] == '0' && expression[indexList.at(i) + 2] != '.')
        {
            QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("除数不能为0"));
            return false;
        }
    }

    //括号的结合匹配
    if(!bracketStack.empty())
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("括号不匹配"));
        return false;
    }
    
    // 表达式不能以运算符结尾
    QString operators = "+-*/";             //记录运算符，用来做校验对比
    if (operators.contains(expression.at(expression.length() - 1)))
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("表达式不能以运算符结尾"));
        return false;
    }



    return true;
}