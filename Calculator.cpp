#include "Calculator.h"
#include <ctype.h>

Calculator::Calculator(){
}

void Calculator::evaluate(std::vector<std::string> input){
    if(input.size()==1){
        expression="Error";
        return;
    }
    for (int i = 0; i < input.size(); i++){
        if(mainStack.empty()==false){
            if (isANumber(input[i])&&isANumber(mainStack.top())&&mainStack.size()>2){
                int b = stoi(input[i]);
                std::string bS = input[i];
                int a = stoi(mainStack.top());
                std::string aS = expressionStack.top();
                mainStack.pop();
                expressionStack.pop();
                if(isANumber(mainStack.top())){
                    expression = "Error";
                    return;
                }
                char c = mainStack.top().front();
                std::string cS = expressionStack.top();
                mainStack.pop();
                expressionStack.pop();
                mainStack.push(calculate(a,b,c));
                expressionStack.push(write(aS,bS,cS));

            }else{
                mainStack.push(input[i]);
                expressionStack.push(input[i]);
            }
        }
        else{
            mainStack.push(input[i]);
            expressionStack.push(input[i]);
        }


    }
    while(mainStack.size()!=1){
        std::string checkTop = mainStack.top();
        mainStack.pop();
        std::string checkSecond = mainStack.top();
        if(isANumber(checkTop)==false||isANumber(checkSecond)==false){
            expression = "Error";
            return;
        }
        mainStack.push(checkTop);
        if(mainStack.size()<3){
            expression = "Error";
            return;
        }

        int b = stoi(mainStack.top());
        mainStack.pop();
        std::string bS = expressionStack.top();
        expressionStack.pop();
        int a = stoi(mainStack.top());
        std::string aS = expressionStack.top();
        mainStack.pop();
        expressionStack.pop();
        if(isANumber(mainStack.top())){
            expression = "Error";
            return;
        }
        char c = mainStack.top().front();
        std::string cS = expressionStack.top();
        mainStack.pop();
        expressionStack.pop();
        if(a)

        mainStack.push(calculate(a,b,c));
        expressionStack.push(write(aS,bS,cS));
    }
    expression = expressionStack.top();
    expression.erase(0,1);
    expression.pop_back();

    expression.append(" = ");
    expression.append(mainStack.top());
    return;
}

bool Calculator::isANumber(std::string input){
    if(input.length()>1){
        return true;
    }
    if((input[0]=='+')||(input[0]=='*')||(input[0]=='/')||(input[0]=='-')){
        return false;
    }else{
        return true;
    }
}

std::string Calculator::calculate(int num1, int num2, char op){
    std::string result;
    if(op=='+'){
        result = std::to_string(num1+num2);
    }else if(op=='-'){
        result =  std::to_string(num1-num2);
    }else if(op=='*'){
        result =  std::to_string(num1*num2);
    }else if(op=='/'){
        result =  std::to_string(num1/num2);
    }else{
        return "Error";
    }
    return result;
}

std::string Calculator::write(std::string a, std::string b, std::string op){
    std::string result;
    if(op=="+"||op=="-"){
        result.append("(");
        added=true;
    }else{
        added=false;
    }
    result.append(a);
    result.append(" ");
    result.append(op);
    result.append(" ");
    result.append(b);
    if(op=="+"||op=="-"){
        result.append(")");
    }
    

    return result;

}

std::string Calculator::getExpression(){
    return expression;
}