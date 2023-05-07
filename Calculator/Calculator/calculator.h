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
    void btnAllClearClicked();      //����������ʽ
    void btnClearLineClicked();     //�����ǰ�����������ֵ
    void btnDelClicked();           //���һ������
    void btnAddClicked();           //��
    void btnSubtractClicked();      //��
    void btnMultiplyClicked();      //��
    void btnDivideClicked();        //��
    void btnEqualClicked();         //�Ⱥš������������ʽ��ֵ
    void btnDotClicked();           //С����
    void btnLeftBracketClicked();   //������
    void btnRightBracketClicked();  //������
    void btn10to2Clicked();         //ʮ����ת������
    void btnSquareClicked();        //ƽ��
    void btnSqrtClicked();          //����
    void btnModClicked();           //����


private:
    Ui::CalculatorClass ui;
    QString currentInputNumbers;    //lcd��ʾ��������ʾ��ǰ�������ֵ
    QString expression;             //line edit��������ʾ������ʽ�������
    QStack<QChar> bracketStack;     //����ջ������ƥ����������
};
