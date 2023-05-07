#pragma once

#include <QtWidgets/QWidget>
#include "ui_calculator.h"
#include <QChar>
#include <QStack>

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

    void initCalculator();
    bool verifyInput();

public slots:
    void num0Clicked();
    void num1Clicked();
    void num2Clicked();
    void num3Clicked();
    void num4Clicked();
    void num5Clicked();
    void num6Clicked();
    void num7Clicked();
    void num8Clicked();
    void num9Clicked();
    void btnAllClearClicked();      //清除整个表达式
    void btnClearLineClicked();     //清除当前输入的整个数值
    void btnDelClicked();           //清除一个输入
    void btnAddClicked();           //加
    void btnSubtractClicked();      //减
    void btnMultiplyClicked();      //乘
    void btnDivideClicked();        //除
    void btnEqualClicked();         //等号。计算整个表达式的值
    void btnDotClicked();           //小数点
    void btnLeftBracketClicked();   //左括号
    void btnRightBracketClicked();  //右括号
    void btn10to2Clicked();         //十进制转二进制
    void btnSquareClicked();        //平方
    void btnSqrtClicked();          //开方
    void btnModClicked();           //求余


private:
    Ui::CalculatorClass ui;
    QString currentInputNumbers;    //lcd显示框，用来显示当前输入的数值
    QString expression;             //line edit，用来显示总体表达式的输入框
    QStack<QChar> bracketStack;     //括号栈，用于匹配左右括号
};
