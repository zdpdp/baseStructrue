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
	void init(treeNode* &p);  //初始数值测试
	bool empty();
	int  depth(treeNode *s);  //计算深度
	int  count(treeNode *s);  //计算数量
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