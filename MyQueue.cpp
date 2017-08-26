#include "MyQueue.h"
#include <iostream>
using namespace std;
MyQueue::MyQueue(int capacity) {
	queue_capacity = capacity;
	queue = new int[capacity];
	clear();
}
MyQueue::~MyQueue() {
	delete []queue;
	queue = nullptr;
}
void MyQueue::clear() {
	head = 0;
	tail = 0;
	queue_length = 0;
}
bool MyQueue::empty() const {
	return queue_length == 0 ? true : false;
}
bool MyQueue::full() const {
	return queue_length == queue_capacity ? true : false;
}
int MyQueue::length() const {
	return queue_length;
}
bool MyQueue::enqueue(int item) {
	if (full()) {
		return false;
	}
	queue[tail] = item; 
	tail++;
	tail = tail % queue_capacity;
	queue_length++;
	return true;
}
int MyQueue::dequeue() {
	if (empty()) {
		throw "╤сап©у";
	}
	int top = queue[head];
	head++;
	
	head = head % queue_capacity;
	queue_length--;
	return top;
}
void MyQueue::traverse() {
	for (int i = 0; i < queue_length; i++) {
		cout << queue[(head+i)%queue_capacity] << "\t";
	}
}
int MyQueue::getHead() {
	if (empty()) {
		return NULL;
	}
	return queue[head];
}
int MyQueue::getTail() {
	if (empty()) {
		return NULL;
	}
	return queue[tail - 1];
}
