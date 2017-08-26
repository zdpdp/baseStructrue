#pragma once
#ifndef GRAPH_H
#define GRAPH_H
class MyGraph {
public:
	MyGraph(int itemNum); //���붥���� ��ʼ��
	~MyGraph();
	void input();
	void randInput(int sideNum); //�ߵ���Ŀ
	void printDFS(int node);
	void printBFS(int start);
	void prim();//����ķ��С������
	void kruskal();//��³˹������С�������㷨 ��̰�ķ� 
	void trasever();
private:
	void DFS(int node);
	void BFS(int start);
	void clearVisited(); //������������
	int itemNum;//������
	char *itemVal; //������������
	int *matrix ; //�ٽӾ���
	int *visited; //������������

	int getNodeToNodeVal(); //
};
#endif