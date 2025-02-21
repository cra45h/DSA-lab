//#define MAX_ITEMS 100
//#include<iostream>
//typedef char ItemType;
//using namespace std;
//class stack
//{
//public:
//	stack();
//	int isEmpty() const;
//	int isFull() const;
//	void Push(ItemType newItem);
//	void Pop(ItemType& item);
//	int Peek(ItemType& item);
//	void reverse(ItemType& s1);
//private:
//	int top;
//	ItemType items[MAX_ITEMS];
//};
#pragma once
#include <iostream>
#include <string>
using namespace std;

template<class ItemType>
class Stack {
public:
    Stack();
    Stack(int max);
    ~Stack();
    int isEmpty() const;
    int isFull() const;
    void Push(ItemType newItem);
    void Pop(ItemType& item);
    ItemType Top() const;

    bool isValidExpression(const string& expression);
    string infToPostfix(const string& infix);
    int evaluatePostfix(const string& postfix);

private:
    int top;
    int maxStack;
    ItemType* items;
    int precedence(char op) const;
};
