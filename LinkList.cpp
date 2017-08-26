#include<iostream>
#include "LinkList.h"
#include<time.h>
using namespace std;
LinkList::LinkList() {
	head = new node;
	rear = head;
	length = 0;
}
LinkList::LinkList(int initData[]) {
	int length = sizeof(initData) / sizeof(int);
	for (int i = 0; i < length;i++) {
		append(initData[i]);
	}
}
LinkList::~LinkList() {

	clear();
	delete head;
}
void LinkList::randAppend(int count) {
	int num = count;
	int temp;
	srand((unsigned)time(NULL));
	while (num > 0) {
		
		temp = rand() % 1000;
		append(temp);
		num--;
	}
}
void LinkList::clear() {
 	node *s = head->next;
	node *p;
	while (s!=NULL) {
		p = s->next;
		delete s;
		s = p;
	}
	head->next = NULL;
	rear = head;
	length = 0;
}
void LinkList::prepend(int item) {
	node *s = new node;
	if (length == 0)
		rear = s;
	s->data = item;
	s->next = head->next;
	head->next = s;
	length++;
}
void LinkList::append(int item) {
	node *s = new node;
	s->data = item;
	rear->next =  s;
	rear = s;
	length++;
}
void LinkList::traverse() {
	node *s = head->next;
	int i = 1;
	while (s!=NULL) {
		cout << s->data << "\t";
		s = s->next;
		if (i % 5 == 0) {
			cout << endl;
		}
		i++;
	}
	cout << endl <<"==========================="<< endl;
}
void LinkList::insert(int item,int position) {
	if (position<0 || position>length) {
		throw "插入位置不合法";
	}
	if (position == 0) {
		prepend(item);
		return;
	}
	if (position == length) {
		append(item);
		return;
	}
	node *p = head;
	node *s = new node;
	s->data = item;
	while (position>0) {
		p = p->next;
		position--;
	}
	s->next = p->next;
	p->next = s;
	length++;
}
void LinkList::del(int position) {
	if (position>length) {
		throw "删除位置不合法";
	}
	int i = 0;
	node *s = head,*p;
	for (int i = 0; i < position; i++) {
		s = s->next;
	}
	p = s->next; //p为需要删除的节点
	if (p == rear) {
		rear = s;
	}
	s->next = p->next;
	delete p;
	length--;

}
void LinkList::reverse() {
	if (length <= 1) {
		return;
	}
	rear = head->next;
	node *s = head, *p = s->next;;
	while (p!= NULL) {
		s = p;
		p = s->next;
		s->next = head->next;
		head->next = s;
	}

	rear->next = NULL;

}
void LinkList::swap(int p1, int p2) {
	if (p1 >= p2) {
		throw "error";
	}
	if (p1<0 || p1>length - 1 || p2<0 || p2>length - 1) {
		throw "error";
	}

	/*操作节点指针交换方式*/

	node *s = head,*p1Ahead,*p2ptr,*p1Next;
	while ((p1--) > 0) {
		s = s->next;
	}
	//p1Ahead->next 是第一个交换位置
	p1Ahead = s;
	p1Next = p1Ahead->next->next;
	if (p2 == length - 1) {
		rear = p1Ahead->next;
	}
	s = head;
	while ((p2--) > 0) {
		s = s->next;
	}
	if (s == p1Ahead->next) {
		//如果要交换的两个位置相邻
		p1Ahead->next = s->next;
		s->next = p1Next->next;
		p1Ahead->next->next = s;

	}
	else {
		p2ptr = s->next;
		//p2ptr 是第二个交换位置
		s->next = p1Ahead->next;
		p1Ahead->next->next = p2ptr->next;
		p2ptr->next = p1Next;
		p1Ahead->next = p2ptr;
	}
	

}
void LinkList::bubbleSort() {
	node *s;
	bool flag;
	int temp;
	for (int i = 0; i < length-1; i++) {
		flag = false;
		s = head->next;
		for (int j = 0; j < length - i-1; j++) {		
			if (s->data > s->next->data) {
				temp = s->data;
				s->data = s->next->data;
				s->next->data = temp;
				flag = true;
			}
			s = s->next;	
		}
		if (!flag)
			break;
	}
}
