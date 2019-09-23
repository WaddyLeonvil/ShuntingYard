#include <iostream>
#include <vector>
using namespace std;
#include <string>
#include "ShuntingYard.h"




int main() {
    ShuntingYard sy;
    string equation;
    cout << "> ";
    getline(cin, equation);
    
    sy.tokenize(equation);
    
    
    return 0;
}

vector<string> ShuntingYard::tokenize(string equation) {
    int index = 0;
    string temp;
    vector<string> result;
    while ((index = equation.find(" ")) != std::string::npos) {
        temp = equation.substr(0, index);
        equation.erase(0, index + 1);
        result.push_back(temp);
    }
    result.push_back(equation);
    
    analyze(result);
    return result;
}

void ShuntingYard::analyze(vector<string> tokenVector) {
    vector<string> output;
    vector<string> operators;
    
    for (int i = 0; i < tokenVector.size(); i++) {
        
        if (tokenVector.at(i)[0] > 47 && tokenVector.at(i)[0] < 58) { // Between 0 and 9
            output.push_back(tokenVector.at(i));
        }
        else if (tokenVector.at(i)[0] == 40) { // Left Parenthesis
            operators.push_back(tokenVector.at(i));
        }
        else if (tokenVector.at(i)[0] == 41) { // Right Parenthesis
            while (operators.back()[0] != 40) {
                output.push_back(operators.back());
                operators.pop_back();
            }
            operators.pop_back();
        }
        else {
            if (!operators.empty()) {
                while(((precedence(operators.back()) > precedence(tokenVector.at(i))) || (precedence(operators.back()) == precedence(tokenVector.at(i)) && leftAsso(operators.back()))) && operators.back()[0] != 40) {
                    output.push_back(operators.back());
                    operators.pop_back();
                    if (operators.empty()) {
                        break;
                    }
                }   
            }
            operators.push_back(tokenVector.at(i));
        }
    }
    
    while (!operators.empty()) {
        output.push_back(operators.back());
        operators.pop_back();
    }
    
    for (int i = 0; i < output.size(); i++) {
        cout << output.at(i) << " ";
    }
    
}

int ShuntingYard::precedence(string token) {
    if (token[0] == 94 || token == "rt") {
        return 4;
    }
    else if (token[0] == 42 || token[0] == 47 || token[0] == 88 || token[0] == 120) {
        return 3;
    }
    else if (token[0] == 43 || token[0] == 45) {
        return 2;
    }
    else {
        return 1;
    }
}

bool ShuntingYard::leftAsso(string token) {
    if (token[0] == 94 || token == "rt") {
        return false;
    }
    else {
        return true;
    }
}