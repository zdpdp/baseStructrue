#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H
struct treeNode {
	char data;
	treeNode *left = NULL;
	treeNode *right = NULL;
};
class BinaryTree {
public:
	BinaryTree();
	~BinaryTree();
	void init(treeNode* &p);  //��ʼ��ֵ����
	bool empty();
	int  depth(treeNode *s);  //�������
	int  count(treeNode *s);  //��������
	void InOrderTraverse(treeNode *p);
	void FirstOrderTraverse(treeNode *p);
	void LastOrderTraverse(treeNode *p);
	void clear(treeNode *s);
	treeNode *base;
private:
	char getTestch();
	char* testString = "ABC##DE#G##F###";
	
};
#endif