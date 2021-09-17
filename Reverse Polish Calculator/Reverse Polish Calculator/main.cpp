//
//  main.cpp
//  LIFO Stack
//
//  Created by Gavin Beck on 13/8/20.
//  Copyright © 2020 Gavin Beck. All rights reserved.
//

#include <iostream>
#include <stack>
#include <sstream>

using namespace std;
// function accepting string value at address 'input'. Passing in what's at that address
bool isOperator(const string& input)
{
    string ops[] = {"-", "+", "*", "/"};
    for(int i = 0; i < 4; i++)
    {
        if(input == ops[i])
        {
            return true;
        }
    }
    return false;
}
void performOp(const string& input, stack<double>& calcStack)
{
    double lVal, rVal, result = 0;
    // retrieve top element of the stack and temporarily store in rVal and lVal. pop off topmost element of the stack
    rVal = calcStack.top();
    calcStack.pop();
    lVal = calcStack.top();
    calcStack.pop();
    // check which operator was inputted
    if(input == "-")
    {
        result = lVal - rVal;
    }
    if(input == "+")
    {
        result = lVal + rVal;
    }
    if(input == "*")
    {
        result = lVal * rVal;
    }
    if(input == "/")
    {
        result = lVal / rVal;
    }
    // push adds new element to top of the stack
    cout << result << endl;
    calcStack.push(result);
}

int main()
{
    double num;
    string input;
    stack<double> calcStack;
    
    cout << "RPN Calculator." << " Press 'q' to quit." << endl;
    
    while(true)
    {
        // display a prompt for calc.
        cout << ">> ";
        cin >> input;
        /* puts 'input' into 'num' if variable is recieved. if variable is recieved, push num on stack */
        if(istringstream(input) >> num)
        {
            calcStack.push(num);
        }
        /* check for operator. If true, send input and clacStack data to performOp. one is a string input (pass by const reference), the other is reference to stack(pass by reference) */
        else if(isOperator(input))
        {
            performOp(input, calcStack);
        }
        // check for quit
        else if(input == "q" || "Q")
        {
            return 0;
        }
    }
}
