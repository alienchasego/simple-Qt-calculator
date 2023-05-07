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

void Calculator::initCalculator()   //��ʼ��������
{
    this->setWindowTitle("calculator");
    ui.lineEdit->setReadOnly(true); //����򲻿ɱ༭��ֻ��ͨ����������
    ui.lcdNumber->display("0"); //��ʼ��ʾ0
}

void Calculator::num0Clicked()      //��������0-9
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

void Calculator::btnAllClearClicked()       //��ձ��ʽ
{
    expression.clear();
    ui.lineEdit->setText(expression);
    currentInputNumbers.clear();
    ui.lcdNumber->display(currentInputNumbers);
    bracketStack.clear();
}

void Calculator::btnClearLineClicked()       //��յ�ǰ�����������ֵ
{
    expression.chop(currentInputNumbers.size());
    ui.lineEdit->setText(expression);
    currentInputNumbers.clear();
    ui.lcdNumber->display(currentInputNumbers);
}

void Calculator::btnDelClicked()            //���һ������
{
    expression.chop(1);
    ui.lineEdit->setText(expression);
    currentInputNumbers.chop(1);
    ui.lcdNumber->display(currentInputNumbers);
    if (expression.at(expression.length() - 1) == '(')          //�������������ţ����⿼��
    {
        bracketStack.pop();
    }
    if (expression.at(expression.length() - 1) == ')')
    {
        bracketStack.push('(');
    }
}

void Calculator::btnAddClicked()            //��
{
    if (expression.isEmpty())return;
    QString operators = "+-*/(";             //��¼�������������У��Ա�
    if (operators.contains(expression.at(expression.length() - 1)))
    {
        QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("�����������������"));
        return;
    }
    currentInputNumbers.clear();
    expression += "+";
    ui.lineEdit->setText(expression);
}

void Calculator::btnSubtractClicked()       //��
{
    if (expression.isEmpty())return;
    QString operators = "+-*/(";             //��¼�������������У��Ա�
    if (operators.contains(expression.at(expression.length() - 1)))
    {
        QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("�����������������"));
        return;
    }
    currentInputNumbers.clear();
    expression += "-";
    ui.lineEdit->setText(expression);
}

void Calculator::btnMultiplyClicked()       //��
{
    if (expression.isEmpty())return;
    QString operators = "+-*/(";             //��¼�������������У��Ա�
    if (operators.contains(expression.at(expression.length() - 1)))
    {
        QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("�����������������"));
        return;
    }
    currentInputNumbers.clear();
    expression += "*";
    ui.lineEdit->setText(expression);
}

void Calculator::btnDivideClicked()         //��
{
    if (expression.isEmpty())return;
    QString operators = "+-*/(";             //��¼�������������У��Ա�
    if (operators.contains(expression.at(expression.length() - 1)))
    {
        QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("�����������������"));
        return;
    }
    currentInputNumbers.clear();
    expression += "/";
    ui.lineEdit->setText(expression);
}

void Calculator::btnEqualClicked()      //�Ⱥż���
{
    if (expression.isEmpty())return;

    currentInputNumbers.clear();

    //��������ʽ�淶����������Ϊ0�����ŵĽ��ƥ�䣬���ʽ�������������β�ȵȵ��ж�
    if (verifyInput() == false) return;

    std::string rpn = toRPN(expression.toStdString()); // ��׺���ʽתΪ�沨�����ʽ
    string resultString = to_string(calculateRPN(rpn));// �����沨�����ʽ��ֵ��ת����string
    resultString= resultString.substr(0, resultString.find_last_not_of('0') + 1);//ȥ��doubleתstring���ɵ�β��0
    if (resultString.back() == '.') resultString.pop_back();//ȥ��ĩβС����
        
    QString resultQString = QString::fromStdString(resultString); //stringתQString
    
    expression += "=" + resultQString;
    ui.lcdNumber->display(resultQString);
    ui.lineEdit->setText(expression);

    currentInputNumbers.clear();
    expression.clear();

}

void Calculator::btnDotClicked()        //С��������
{
    if (currentInputNumbers.isEmpty())return;                     //С����ǰû����ֵʱ��������С����
    if (currentInputNumbers.lastIndexOf('.') != -1)return;      //����һ����ֵʱ�����ɶ������С����
    expression += ".";
    currentInputNumbers += ".";
    ui.lcdNumber->display(currentInputNumbers);
    ui.lineEdit->setText(expression);
    return;

}

void Calculator::btnLeftBracketClicked()    //������
{
    QString operators = "+-*/";             //��¼�������������У��Ա�
    if (operators.contains(expression.at(expression.length() - 1)))
    {
        currentInputNumbers.clear();
        expression += "(";
        bracketStack.push('(');
        ui.lineEdit->setText(expression);
    }
    return;
}

void Calculator::btnRightBracketClicked()       //������
{
    QString operators = "+-*/(";             //��¼�������������У��Ա�
    if (operators.contains(expression.at(expression.length() - 1)))    return;
    if (bracketStack.empty())return;            //���û�������ţ���������������
    bracketStack.pop();                         //ÿ����һ�������ţ�ƥ��һ��������
    currentInputNumbers.clear();
    expression += ")";
    ui.lineEdit->setText(expression);
    return;
}

void Calculator::btn10to2Clicked()     //ʮ����ת������
{
    bool isAllDigit;
    int result = expression.toInt(&isAllDigit);
    if (isAllDigit)
    {
        std::bitset<sizeof(result) * 8> binary(result);
        QString resultString = QString::fromStdString(binary.to_string());
        ui.lcdNumber->display(resultString);
    }
    else QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("����ת��ʱ�����ʽӦֻ������"));
    return;
}

void Calculator::btnSquareClicked()     //ƽ��
{
    bool isAllDigit;
    double result=expression.toDouble(&isAllDigit);
    if (isAllDigit)
    {
        ui.lcdNumber->display(result* result);
    }   
    else QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("����ƽ��ʱ�����ʽӦֻ������ֵ"));
    return;
}

void Calculator::btnSqrtClicked()       //����
{
    bool isAllDigit;
    double result = expression.toDouble(&isAllDigit);
    if (isAllDigit)
    {
        ui.lcdNumber->display(sqrt(result));
    }
    else QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("���㿪��ʱ�����ʽӦֻ������ֵ"));
    return;
}

void Calculator::btnModClicked()        //����
{
    if (expression.contains('%'))
    {
        QStringList parts = expression.split('%'); // ��'%'Ϊ�ָ���
        QString part1 = parts[0]; // ��ȡ�ָ��ĵ�һ���Ӵ�
        QString part2 = parts[1]; // ��ȡ�ָ��ĵڶ����Ӵ�
        bool isAllDigit_1, isAllDigit_2;
        int num1 = part1.toInt(&isAllDigit_1);
        int num2 = part2.toInt(&isAllDigit_2);
        if (isAllDigit_1 && isAllDigit_2)
        {
            ui.lcdNumber->display(num1 % num2);
        }
        else QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("��������ʱ�����ʽ��ʽӦΪ��a%b��"));
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
{   //��������ʽ�淶����������Ϊ0�����ŵĽ��ƥ�䣬���ʽ�������������β�ȵȵ��ж�

    //����Ϊ���ж�
    QList<int> indexList;

    int index = expression.indexOf('/');
    while (index >= 0)
    {
        indexList.append(index);
        index = expression.indexOf('/', index + 1);
    }

    // ��ÿ����/�������ж�
    for (int i = 0; i < indexList.size(); ++i)
    {
        if (expression[indexList.at(i) + 1] == '0' && expression[indexList.at(i) + 2] != '.')
        {
            QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("��������Ϊ0"));
            return false;
        }
    }

    //���ŵĽ��ƥ��
    if(!bracketStack.empty())
    {
        QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("���Ų�ƥ��"));
        return false;
    }
    
    // ���ʽ�������������β
    QString operators = "+-*/";             //��¼�������������У��Ա�
    if (operators.contains(expression.at(expression.length() - 1)))
    {
        QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("���ʽ�������������β"));
        return false;
    }



    return true;
}