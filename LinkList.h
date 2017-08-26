#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H
struct node
{
	node *next = nullptr;
	int  data;
};
class LinkList {
public:
	LinkList();
	LinkList(int initData[]);
	~LinkList();
	void append(int item);		//尾插
	void randAppend(int count);  //随机插入多少个数据
	void insert(int item, int position);  //指定位置插入数据 位置从0开始算起
	void clear();
	void prepend(int item);		 //头插
	void del(int position);		 //删除指定位置 位置从0开始算起
	void traverse();			//打印
	void reverse();  //翻转
	void swap(int p1, int p2); //p1和p2位置的节点互换
	void bubbleSort();//冒泡排序

private:
	node *head;
	node *rear;
	int length;
};
#endif