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
	void append(int item);		//β��
	void randAppend(int count);  //���������ٸ�����
	void insert(int item, int position);  //ָ��λ�ò������� λ�ô�0��ʼ����
	void clear();
	void prepend(int item);		 //ͷ��
	void del(int position);		 //ɾ��ָ��λ�� λ�ô�0��ʼ����
	void traverse();			//��ӡ
	void reverse();  //��ת
	void swap(int p1, int p2); //p1��p2λ�õĽڵ㻥��
	void bubbleSort();//ð������

private:
	node *head;
	node *rear;
	int length;
};
#endif