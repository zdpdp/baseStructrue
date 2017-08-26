#include<iostream>
#include "MyGraph.h"
#include "SequenceList.h"
#include<time.h>
#include<vector>
#include "MyQueue.h"
using namespace std;
struct side {
	int head;//边上的起点
	int tail;//边上的终点
	int val;//边上的权值
	
};
MyGraph::MyGraph(int num) {
	itemNum = num;
	matrix = new int[itemNum*itemNum];
	itemVal = new char[itemNum];
	visited = new int[itemNum];
	for (int i = 0; i < itemNum*itemNum; i++) {
		//矩阵初始化
		matrix[i] = 0;
	}
	for (int i = 0; i < itemNum; i++) {
		//顶点初始化
		itemVal[i] = 65;
	}
		//访问数组初始化
	clearVisited();
	
}
MyGraph::~MyGraph() {
	delete []matrix;
	delete []itemVal;
	delete []visited;
}
void MyGraph::clearVisited() {
	int j = itemNum;
	while (j-- > 0) {
		visited[j] = 0;
	}
}
void MyGraph::randInput(int sideNum) {
	int a,b,val,count; //a 顶点1  b顶点2  val权值
	srand((unsigned)time(NULL)); //设置随机种子

	
	int x = itemNum*itemNum;
	for (int i = 0; i < itemNum; i++) {
		itemVal[i] = rand() % 26 + 65; //随机赋值
	}
	while (sideNum-- > 0) {
		a = rand() % itemNum;   
		b = rand() % itemNum;
		val = rand() % 100 + 1; 

		//二维数组 一维化  第a行第b列 = a * itemNum + b  ;
		matrix[a*itemNum + b] = val;
		matrix[b*itemNum + a] = val;  //对称数组
	}
	
}
void MyGraph::input() {

	int init[10][3] = { {0,2,1},{0,1,6},{0,3,5},{1,2,5},{2,3,5},{1,4,3},{2,4,6},{2,5,4},{4,5,6},{3,5,2} };
	int i = 0;
	while (i<10) {
		//二维数组 一维化  第a行第b列 = a * itemNum + b  ;
		matrix[init[i][0]*itemNum + init[i][1]] = init[i][2];
		matrix[init[i][1] * itemNum + init[i][0]] = init[i][2];
		i++;
	}
	
	
}
void MyGraph::printDFS(int node) {
	clearVisited();
	cout << "=======DFS=======" << endl;
	DFS(node);
}
void MyGraph::printBFS(int node) {
	clearVisited();
	cout << "=======DFS=======" << endl;
	BFS(node);
}
void MyGraph::DFS(int node) {

	cout << "DFS第"<<node<<"个节点:"<<itemVal[node] << endl;
	visited[node] = 1;
	for (int i = 0; i < itemNum; i++) {
		//依次查找矩阵第 node行
		if (matrix[node*itemNum+i]) {
			if (!visited[i]) {
				DFS(i);
			}
		}
	}
}
void MyGraph::BFS(int start) {

	MyQueue *q = new MyQueue(itemNum);
	q->enqueue(start);
	visited[start] = 1;
	while (!q->empty()) {
		int node = q->dequeue();
		cout << "BFS第" << node << "个节点:" << itemVal[node] << endl;
		for (int i = 0; i < itemNum; i++) {
			//依次查找矩阵第 node行
			if (matrix[node*itemNum+i]) {
				if (!visited[i]) {
					q->enqueue(i);
					visited[i] = 1;
				}
			}
		}
	}
	delete q;
	q = nullptr;
}
void MyGraph::prim() {
	cout << "==========prim算法最小生成树==========" << endl;
	trasever();
	SequenceList *v = new SequenceList(itemNum);
	SequenceList *U = new SequenceList(itemNum);
	int *NewMatrix = new int[itemNum*itemNum];
	for (int i = 0; i < itemNum*itemNum; i++) {
		//新矩阵初始化
		NewMatrix[i] = 0;
	}
	int *closedge = new int[itemNum];
	int *closedgeToNode = new int[itemNum];
	for (int i = 0; i < itemNum; i++) {
		closedge[i]= 99999;
	}
	for (int i = 1; i < itemNum; i++) {
		//除了初始顶点以外
		v->insert(i);
	}
	U->insert(0); //初始顶点插入U集合中
	while (U->length() < itemNum) {
		int min = NULL; 
		int minNode = NULL;
		for (int i = 0; i < v->length(); i++) {
			int node = v->get(i); //node为节点
			//求出node节点到连通分支的 最短路径（U集合每个点都求一次)

			for (int j = 0; j < U->length(); j++) {
				int temp = matrix[node * itemNum + U->get(j)];
				if (temp>0&&temp < closedge[node]) {

					closedge[node] = temp;
					closedgeToNode[node] = U->get(j);
				}
			}
	
			//记录最小的closedge
			if (closedge[node] < min||min==NULL) {
				min = closedge[node];
				minNode = node;

			}
		}
		NewMatrix[minNode * itemNum + closedgeToNode[minNode]] = min;
		NewMatrix[closedgeToNode[minNode] * itemNum +minNode ] = min;
		cout << "v" << minNode+1 << "与v" << closedgeToNode[minNode]+1 << "相连，权值是：" << min << endl;
		v->del(minNode);
		U->insert(minNode);		
	}
	delete v;
	delete U;
	delete[]NewMatrix;
	delete[]closedge;
	delete[]closedgeToNode;
}
void MyGraph::kruskal() {
	vector<side> Edge;
	cout << "==========kruskal算法最小生成树==========" << endl;
	//创建Edge数组，因为对称 所以只求下三角
	for (int i = 1; i < itemNum; i++) {
		for (int j = 0; j < i; j++) {
			if (matrix[i*itemNum + j]>0) {
				side x = side();
				x.head = j;
				x.tail = i;
				x.val = matrix[i*itemNum + j];
				Edge.push_back(x);
			}
		}
	}
	//Edge数组排序
	for (int i = 0; i < Edge.size(); i++) {
		int key = i;
		for (int j = i+1; j < Edge.size(); j++) {
			if (Edge[j].val < Edge[key].val) {
				key = j;
			}
		}
		side temp = Edge[i];
		Edge[i] = Edge[key];
		Edge[key] = temp;
	}
	//连通分支初始化 每个点都属于一个连通分量
	int *vexset = new int[itemNum];
	for (int i = 0; i < itemNum; i++) {
		vexset[i] = i;
	}
	for (int i = 0; i < Edge.size(); i++) {
		cout << "头:v"<<Edge[i].head+1 << " 尾:v" << Edge[i].tail+1 << " 权值" << Edge[i].val << endl;
	}
	for (int i = 0; i < Edge.size(); i++) {
		int s1 = vexset[Edge[i].head];//获取起点所在连通分量
		int s2 = vexset[Edge[i].tail];//获取终点所在连通分量
		if (s1 != s2) {
			//两个点不属于同一个连通分量
			//修改所有 连通分量为s1都改为s1
			for (int j = 0; j < itemNum; j++) {
				if (vexset[j] == s2) {
					vexset[j] = s1;
				}
			}
			cout << "v" << Edge[i].head + 1 << "连上v" << Edge[i].tail + 1 << endl; 
				
		}
	}



}
void MyGraph::trasever() {
	cout << "------临接矩阵-------" << endl;
	for (int i = 0; i < itemNum; i++) {
		for (int j = 0; j < itemNum; j++) {
			cout << matrix[i*itemNum + j] << "\t";
		}
		cout << endl;
	}
}