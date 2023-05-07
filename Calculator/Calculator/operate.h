#pragma once

#include <string>
#include <stack>
#include <cmath>

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int getPriority(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else {
        return 0;
    }
}

std::string toRPN(std::string expr) {
    std::string rpn;
    std::stack<char> opStack;
    for (char c : expr) {
        if (isdigit(c) || c == '.') {
            rpn.push_back(c);
        }
        else if (isOperator(c)) {
            rpn.push_back(' ');
            while (!opStack.empty() && getPriority(opStack.top()) >= getPriority(c)) {
                rpn.push_back(opStack.top());
                rpn.push_back(' ');
                opStack.pop();
            }
            opStack.push(c);
        }
        else if (c == '(') {
            opStack.push(c);
        }
        else if (c == ')') {
            while (opStack.top() != '(') {
                rpn.push_back(' ');
                rpn.push_back(opStack.top());
                opStack.pop();
            }
            opStack.pop();
        }
    }
    while (!opStack.empty()) {
        rpn.push_back(' ');
        rpn.push_back(opStack.top());
        opStack.pop();
    }
    return rpn;
}

double calculate(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    default: return 0;
    }
}

double calculateRPN(std::string rpn) {
    std::stack<double> numStack;
    for (int i = 0; i < rpn.size(); i++) {
        char c = rpn[i];
        if (isdigit(c) || c == '.') {
            int j = i + 1;
            while (j < rpn.size() && (isdigit(rpn[j]) || rpn[j] == '.')) {
                j++;
            }
            double num = stod(rpn.substr(i, j - i));
            numStack.push(num);
            i = j - 1;
        }
        else if (isOperator(c)) {
            double b = numStack.top();
            numStack.pop();
            double a = numStack.top();
            numStack.pop();
            numStack.push(calculate(a, b, c));
        }
    }
    return numStack.top();
}

