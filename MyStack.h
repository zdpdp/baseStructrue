#pragma once
#ifndef MYSTACK_H
#define MYSTACK_H
class MyStack {
public:
	MyStack(int capacity);
	~MyStack();
	bool empty();
	bool full();
	int length();
	bool push(int item);
	int  pop();
	void traverse();
	int  getTop();
	void clear();
private:
	int *stack;
	int top;
	int stack_capacity;
};
#endif