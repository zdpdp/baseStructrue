#pragma once
#ifndef GRAPH_H
#define GRAPH_H
class MyGraph {
public:
	MyGraph(int itemNum); //输入顶点数 初始化
	~MyGraph();
	void input();
	void randInput(int sideNum); //边的数目
	void printDFS(int node);
	void printBFS(int start);
	void prim();//普里姆最小生成树
	void kruskal();//克鲁斯卡尔最小生成树算法 （贪心法 
	void trasever();
private:
	void DFS(int node);
	void BFS(int start);
	void clearVisited(); //访问数组重置
	int itemNum;//顶点数
	char *itemVal; //顶点数据数组
	int *matrix ; //临接矩阵
	int *visited; //辅助访问数组

	int getNodeToNodeVal(); //
};
#endif