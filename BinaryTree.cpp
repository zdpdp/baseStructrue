#include<iostream>
#include "BinaryTree.h"
using namespace std;
BinaryTree::BinaryTree() {
	init(base);
}
BinaryTree::~BinaryTree() {
	clear(base);
}
void BinaryTree::clear(treeNode *s) {
	if (s == NULL) {
		return;
	}
	clear(s->left);
	clear(s->right);
	delete s;
}
void BinaryTree::init(treeNode* &s) {
	char ch = getTestch();
	if (ch == '#') {
		return;
	}
	else {
		treeNode *p = new treeNode;
		p->data = ch;
		init(p->left);
		init(p->right);
		s = p;
	}
}
void BinaryTree::FirstOrderTraverse(treeNode *p) {
	static int i = 1;
	cout << p->data << "\t";
	if (i % 5 == 0) {
		cout << endl;
	}
	i++;
	FirstOrderTraverse(p->left);
	FirstOrderTraverse(p->right);

}
void BinaryTree::LastOrderTraverse(treeNode *p) {
	static int i = 1;
	LastOrderTraverse(p->left);
	LastOrderTraverse(p->right);
	cout << p->data << "\t";
	if (i % 5 == 0) {
		cout << endl;
	}
	i++;
}
void BinaryTree::InOrderTraverse(treeNode *p) {
	static int i = 1;
	if (p == NULL)
		return;
	InOrderTraverse(p->left);
	cout << p->data << "\t";
	if (i % 5 == 0) {
		cout << endl;
	}
	i++;
	InOrderTraverse(p->right);
	
}
char BinaryTree::getTestch() {

	static int i = 0;
	return testString[i++];

}
bool BinaryTree::empty() {
	if (base == NULL) {
		return true;
	}
	else {
		return false;
	}
}
int  BinaryTree::depth(treeNode *s) {
	if (s == NULL) {
		return 0;
	}
	int m = depth(s->left);
	int n = depth(s->right);
	return m > n ? m + 1 : n + 1;
}
int  BinaryTree::count(treeNode *s) {
	if (s == NULL) {
		return 0;
	}
	int m = count(s->left);
	int n = count(s -> right);
	return m + n + 1;
}