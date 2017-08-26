#include<iostream>
#include "MyGraph.h"
#include "SequenceList.h"
#include<time.h>
#include<vector>
#include "MyQueue.h"
using namespace std;
struct side {
	int head;//���ϵ����
	int tail;//���ϵ��յ�
	int val;//���ϵ�Ȩֵ
	
};
MyGraph::MyGraph(int num) {
	itemNum = num;
	matrix = new int[itemNum*itemNum];
	itemVal = new char[itemNum];
	visited = new int[itemNum];
	for (int i = 0; i < itemNum*itemNum; i++) {
		//�����ʼ��
		matrix[i] = 0;
	}
	for (int i = 0; i < itemNum; i++) {
		//�����ʼ��
		itemVal[i] = 65;
	}
		//���������ʼ��
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
	int a,b,val,count; //a ����1  b����2  valȨֵ
	srand((unsigned)time(NULL)); //�����������

	
	int x = itemNum*itemNum;
	for (int i = 0; i < itemNum; i++) {
		itemVal[i] = rand() % 26 + 65; //�����ֵ
	}
	while (sideNum-- > 0) {
		a = rand() % itemNum;   
		b = rand() % itemNum;
		val = rand() % 100 + 1; 

		//��ά���� һά��  ��a�е�b�� = a * itemNum + b  ;
		matrix[a*itemNum + b] = val;
		matrix[b*itemNum + a] = val;  //�Գ�����
	}
	
}
void MyGraph::input() {

	int init[10][3] = { {0,2,1},{0,1,6},{0,3,5},{1,2,5},{2,3,5},{1,4,3},{2,4,6},{2,5,4},{4,5,6},{3,5,2} };
	int i = 0;
	while (i<10) {
		//��ά���� һά��  ��a�е�b�� = a * itemNum + b  ;
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

	cout << "DFS��"<<node<<"���ڵ�:"<<itemVal[node] << endl;
	visited[node] = 1;
	for (int i = 0; i < itemNum; i++) {
		//���β��Ҿ���� node��
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
		cout << "BFS��" << node << "���ڵ�:" << itemVal[node] << endl;
		for (int i = 0; i < itemNum; i++) {
			//���β��Ҿ���� node��
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
	cout << "==========prim�㷨��С������==========" << endl;
	trasever();
	SequenceList *v = new SequenceList(itemNum);
	SequenceList *U = new SequenceList(itemNum);
	int *NewMatrix = new int[itemNum*itemNum];
	for (int i = 0; i < itemNum*itemNum; i++) {
		//�¾����ʼ��
		NewMatrix[i] = 0;
	}
	int *closedge = new int[itemNum];
	int *closedgeToNode = new int[itemNum];
	for (int i = 0; i < itemNum; i++) {
		closedge[i]= 99999;
	}
	for (int i = 1; i < itemNum; i++) {
		//���˳�ʼ��������
		v->insert(i);
	}
	U->insert(0); //��ʼ�������U������
	while (U->length() < itemNum) {
		int min = NULL; 
		int minNode = NULL;
		for (int i = 0; i < v->length(); i++) {
			int node = v->get(i); //nodeΪ�ڵ�
			//���node�ڵ㵽��ͨ��֧�� ���·����U����ÿ���㶼��һ��)

			for (int j = 0; j < U->length(); j++) {
				int temp = matrix[node * itemNum + U->get(j)];
				if (temp>0&&temp < closedge[node]) {

					closedge[node] = temp;
					closedgeToNode[node] = U->get(j);
				}
			}
	
			//��¼��С��closedge
			if (closedge[node] < min||min==NULL) {
				min = closedge[node];
				minNode = node;

			}
		}
		NewMatrix[minNode * itemNum + closedgeToNode[minNode]] = min;
		NewMatrix[closedgeToNode[minNode] * itemNum +minNode ] = min;
		cout << "v" << minNode+1 << "��v" << closedgeToNode[minNode]+1 << "������Ȩֵ�ǣ�" << min << endl;
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
	cout << "==========kruskal�㷨��С������==========" << endl;
	//����Edge���飬��Ϊ�Գ� ����ֻ��������
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
	//Edge��������
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
	//��ͨ��֧��ʼ�� ÿ���㶼����һ����ͨ����
	int *vexset = new int[itemNum];
	for (int i = 0; i < itemNum; i++) {
		vexset[i] = i;
	}
	for (int i = 0; i < Edge.size(); i++) {
		cout << "ͷ:v"<<Edge[i].head+1 << " β:v" << Edge[i].tail+1 << " Ȩֵ" << Edge[i].val << endl;
	}
	for (int i = 0; i < Edge.size(); i++) {
		int s1 = vexset[Edge[i].head];//��ȡ���������ͨ����
		int s2 = vexset[Edge[i].tail];//��ȡ�յ�������ͨ����
		if (s1 != s2) {
			//�����㲻����ͬһ����ͨ����
			//�޸����� ��ͨ����Ϊs1����Ϊs1
			for (int j = 0; j < itemNum; j++) {
				if (vexset[j] == s2) {
					vexset[j] = s1;
				}
			}
			cout << "v" << Edge[i].head + 1 << "����v" << Edge[i].tail + 1 << endl; 
				
		}
	}



}
void MyGraph::trasever() {
	cout << "------�ٽӾ���-------" << endl;
	for (int i = 0; i < itemNum; i++) {
		for (int j = 0; j < itemNum; j++) {
			cout << matrix[i*itemNum + j] << "\t";
		}
		cout << endl;
	}
}