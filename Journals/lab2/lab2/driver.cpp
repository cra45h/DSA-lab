//#include"stack.h"
//int main() {
//	stack s;
//	char item;
//	int var;
//	for (char i = 'a'; i < 'z'; i++) {
//		s.Push(i);
//	}
//
//	for (int i = 0; i < 25; i++) {
//		s.reverse(item);
//	}
//	/*var = s.Peek(item);
//	cout << var;*/
//	return 0;
//}
#include "stack.cpp"
#include <iostream>
using namespace std;

int main() {
    string expression = "((6-(2+3))*(3+8/2))^2+3";

    Stack<char> charStack;
    Stack<int> intStack;

    if (!charStack.isValidExpression(expression)) {
        cout << "Invalid expression!" << endl;
        return 1;
    }

    string postfix = charStack.infToPostfix(expression);
    cout << "Postfix expression: " << postfix << endl;

    int result = intStack.evaluatePostfix(postfix);
    cout << "Result of evaluation: " << result << endl;

    return 0;
}