#pragma once
#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H
class SequenceList {
public:
	SequenceList(int capacity);
	~SequenceList();
	bool insert(int item,int position);
	bool insert(int item); //Ĭ����β������
	int get(int location); //��ȡ
	int  insertWithSort(int item); //�������
	int  length();   //���س���
	bool full();
	bool empty();
	void clear();
	void randInsert(int range); //���������
	int  search(int item);//˳�����
	int  binarySearch(int item); //���ֲ���
	bool del(int data); //ɾ��ĳ������
	bool delLocation(int p);

	void bubbleSort();   //ð������
	void doubleWayBubbleSort(); //˫��ð������
	void RecQuickSort(int low, int high); //��������ݹ��
	void quickSort();    //��������ǵݹ��
	void selectSort();   //ѡ������
	void insertSort(int low,int high);   //��������
	void binaryInsertSort(); //�۰��������
	void mergeSort(int low,int high);    //�鲢����
	void shellSort();    //ϣ������(��С����)
	void heapSort();     //������
	 

	void traverse();     //��ӡ
	void test(int times, int range);
private:
	int *sequence;
	int Sequence_length;  //����
	int Sequence_capacity;
	void swap(int &a, int &b);
	void merge(int low, int mid,int high); //������������ĺϲ�
	void createHeap();
	void headpAjust(int s, int m); //sΪ���ڵ� mΪ����
};
#endif