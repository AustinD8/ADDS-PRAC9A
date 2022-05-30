#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <vector>
#include <string>
#include <stack>

class Calculator{
private:
std::string expression;
std::stack<std::string> mainStack;
std::stack<std::string> expressionStack;
bool added;
public:
void evaluate(std::vector<std::string> input);
std::string calculate(int num1, int num2, char op);
std::string write(std::string a, std::string b, std::string op);
bool isANumber(std::string input);
Calculator();
std::string getExpression();

};
#endif