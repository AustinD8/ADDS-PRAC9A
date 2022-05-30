#include <iostream>
#include <vector>
#include <string>
#include "Calculator.h"

int main(){

    std::string input;
    std::getline(std::cin,input);
    int numPos=0;
    std::vector<std::string> vectorInput;
    std::string word;
    for(int i = numPos; i < input.length(); i++){
        if(input[i]==(' ')){
            if(numPos==0){
                numPos=-1;
            }
            for(int j = numPos+1; j < i; j++){
                word.push_back(input[j]);

            }
            vectorInput.push_back(word);
            word.clear();
            numPos=i;
            
        }
        

        if(i==input.length()-1){
            for(int j = numPos+1; j < input.length(); j++){
                word.push_back(input[j]);

            }
            vectorInput.push_back(word);
            word.clear();
            numPos=i;
        }
    }

    Calculator calc = Calculator();
    calc.evaluate(vectorInput);
    std::cout<<calc.getExpression();
    

    return 0;
}