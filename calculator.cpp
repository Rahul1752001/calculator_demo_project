#include "calculator.h"
#include <stdexcept>
#include <vector>
#include <cmath>
#include <cctype>

using namespace std;

double Calculator::evaluate(const string& expression) {
    
    vector<double> numbers;
    
    vector<char> operators;

    auto applyOperation = [&]() {
        if (numbers.size() < 2 || operators.empty())
            throw invalid_argument("Invalid expression");

        double b = numbers.back();
        numbers.pop_back();
        double a = numbers.back();
        numbers.pop_back();
        char op = operators.back();
        operators.pop_back();

        switch (op) {
            case '+':
                numbers.push_back(a + b);
                break;
            case '-':
                numbers.push_back(a - b);
                break;
            case '*':
                numbers.push_back(a * b);
                break;
            case '/':
                if (b == 0) throw invalid_argument("Cannot Division by zero");
                numbers.push_back(a / b);
                break;
            case '%':
                numbers.push_back(a * (b / 100.0));
                break;
            default:
                throw invalid_argument("Invalid operator");
        }
    };

    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];

        if (isspace(c)) {
            continue; // Ignore whitespace
        } else if (isdigit(c) || c == '.') {
            size_t j = i;
            while (j < expression.size() && (isdigit(expression[j]) || expression[j] == '.')) {
                ++j;
            }
            double number = stod(expression.substr(i, j - i));
            numbers.push_back(number);
            i = j - 1;
        } else if (c == '(') {
            operators.push_back(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.back() != '(') {
                applyOperation();
            }
            if (operators.empty()) throw invalid_argument("Mismatched parentheses");
            operators.pop_back(); // Discard the opening parenthesis
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {
            while (!operators.empty() && (operators.back() == '+' || operators.back() == '-' ||
                                           operators.back() == '*' || operators.back() == '/' || operators.back() == '%')) {
                applyOperation();
            }
            operators.push_back(c);
        } else if (c == '=') {
            while (!operators.empty()) {
                applyOperation();
            }
            if (numbers.size() != 1) throw invalid_argument("Invalid expression");
            return numbers.back();
        } else {
            throw invalid_argument("Invalid character: " + string(1, c));
        }
    }

    while (!operators.empty()) {
        applyOperation();
    }

    if (numbers.size() != 1) throw invalid_argument("Invalid expression");
    return numbers.back();
}
