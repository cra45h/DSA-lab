//#include "stack.h"
//#include <stdlib.h>
//
//stack::stack() 
//{
//	top = -1;
//}
//int stack::isEmpty() const
//{
//	return (top == -1);
//}
//int stack::isFull() const {
//	return (top == MAX_ITEMS - 1);
//}
//void stack::Push(ItemType newItem) {
//	if (isFull())
//	{
//		cout << "Stack Overflow" << endl;
//		exit(1);
//	}
//	top++;
//	items[top] = newItem;
//}
//void stack::Pop(ItemType& item) {
//	if (isEmpty()) {
//		cout << "Stack underflow" << endl;
//		exit(1);
//	}
//	item = items[top];
//	top--;
//}
//int stack::Peek(ItemType& item) {
//	if (isEmpty()) {
//		cout << "Stack underflow" << endl;
//		exit(1);
//	}
//	item = items[top];
//	return item;
//}
//void stack::reverse(ItemType& item) {
//	item = items[top];
//	top--;
//	cout << item << endl;
//}
#include "stack.h"

template<class ItemType>
Stack<ItemType>::Stack() {
    maxStack = 500;
    top = -1;
    items = new ItemType[maxStack];
}

template<class ItemType>
Stack<ItemType>::Stack(int max) {
    maxStack = max;
    top = -1;
    items = new ItemType[max];
}

template<class ItemType>
Stack<ItemType>::~Stack() {
    delete[] items;
}

template<class ItemType>
int Stack<ItemType>::isEmpty() const {
    return (top == -1);
}

template<class ItemType>
int Stack<ItemType>::isFull() const {
    return (top == maxStack - 1);
}

template<class ItemType>
void Stack<ItemType>::Push(ItemType newItem) {
    if (isFull()) {
        cout << "Stack Overflow" << endl;
        exit(1);
    }
    top++;
    items[top] = newItem;
}

template<class ItemType>
void Stack<ItemType>::Pop(ItemType& item) {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        exit(1);
    }
    item = items[top];
    top--;
}

template<class ItemType>
ItemType Stack<ItemType>::Top() const {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        exit(1);
    }
    return items[top];
}

template<class ItemType>
int Stack<ItemType>::precedence(char op) const {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1; // For parentheses
}

template<class ItemType>
bool Stack<ItemType>::isValidExpression(const string& expression) {
    Stack<char> st;
    for (char ch : expression) {
        if (ch == '(') {
            st.Push(ch);
        }
        else if (ch == ')') {
            if (st.isEmpty() || st.Top() != '(') {
                return false; 
            }
            char temp;
            st.Pop(temp);
        }
    }
    return st.isEmpty(); 
}

template<class ItemType>
string Stack<ItemType>::infToPostfix(const string& infix) {
    Stack<char> st;
    string postfix;

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            st.Push(ch);
        }
        else if (ch == ')') {
            while (!st.isEmpty() && st.Top() != '(') {
                postfix += st.Top();
                char temp;
                st.Pop(temp);
            }
            char temp;
            st.Pop(temp); 
        }
        else {
            while (!st.isEmpty() && precedence(st.Top()) >= precedence(ch)) {
                postfix += st.Top();
                char temp;
                st.Pop(temp);
            }
            st.Push(ch);
        }
    }

    while (!st.isEmpty()) {
        postfix += st.Top();
        char temp;
        st.Pop(temp);
    }

    return postfix;
}

template<class ItemType>
int Stack<ItemType>::evaluatePostfix(const string& postfix) {
    Stack<int> st;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            st.Push(ch - '0');
        }
        else {
            int operand1, operand2;
            st.Pop(operand1);
            st.Pop(operand2);

            switch (ch) {
            case '+': st.Push(operand2 + operand1); break;
            case '-': st.Push(operand2 - operand1); break;
            case '*': st.Push(operand2 * operand1); break;
            case '/': st.Push(operand2 / operand1); break;
            case '^': st.Push(pow(operand2, operand1)); break;
            default: break;
            }
        }
    }

    int result;
    st.Pop(result);
    return result;
}