#include<iostream>
#include "MyStack.h"
using namespace std;
MyStack::MyStack(int capacity) {
	stack_capacity = capacity;
	stack = new int[stack_capacity];
	clear();
}
bool MyStack::empty() {
	return top == 0 ? true : false;
}
bool MyStack::full() {
	return top == stack_capacity ? true : false;
}
bool MyStack::push(int item) {
	if (full()) {
		return false;
	}
	stack[top] = item;
	top++;
}
int MyStack::pop() {
	if (empty()) {
		return NULL;
	}
	
	return stack[--top];
}
void MyStack::clear() {
	top = 0;
}
void MyStack::traverse() {
	for (int i = 0; i < top; i++) {
		cout << stack[i] << endl;
	}
}
int MyStack::length() {
	return top;
}
int MyStack::getTop() {
	if (empty()) {
		return NULL;
	}
	return stack[top - 1];
}
MyStack::~MyStack() {
	delete []stack;
	stack = nullptr;
}