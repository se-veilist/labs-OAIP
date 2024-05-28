//Написать программу формирования ОПЗ и расчета полученного
//выражения.Разработать удобный интерфейс ввода исходных данных и вывода
//результатов.Язык программирования С++.Работу программы проверить на
//конкретном примере : (a + b) * (c - d) / e
//a = 7.4; b = 3.6; c = 2.8; d = 9.5; e = 0.9
//Результат = -81,89
#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

double calculate(double operand1, double operand2, char op) {
    switch (op) {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    default:
        return 0;
    }
}

double evaluateExpression(string expression) {
    stack<double> operands;
    stack<char> operators;

    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];
        if (isspace(c))
            continue;

        if (isdigit(c) || c == '.') {
            string numberStr;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                numberStr += expression[i];
                i++;
            }
            i--;
            double operand = stod(numberStr);
            operands.push(operand);
        }
        else if (isOperator(c)) {
            while (!operators.empty() && isOperator(operators.top()) && getPrecedence(operators.top()) >= getPrecedence(c)) {
                double operand2 = operands.top();
                operands.pop();
                double operand1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                double result = calculate(operand1, operand2, op);
                operands.push(result);
            }
            operators.push(c);
        }
        else if (c == '(') {
            operators.push(c);
        }
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double operand2 = operands.top();
                operands.pop();
                double operand1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                double result = calculate(operand1, operand2, op);
                operands.push(result);
            }
            if (!operators.empty())
                operators.pop();
        }
    }

    while (!operators.empty()) {
        double operand2 = operands.top();
        operands.pop();
        double operand1 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        double result = calculate(operand1, operand2, op);
        operands.push(result);
    }

    return operands.top();
}

int main() {
    string expression = "(7.4+3.6)*(2.8-9.5)/0.9";
    double result = evaluateExpression(expression);

    cout << "Result: " << result << endl;

    return 0;
}