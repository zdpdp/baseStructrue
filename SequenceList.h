#pragma once
#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H
class SequenceList {
public:
	SequenceList(int capacity);
	~SequenceList();
	bool insert(int item,int position);
	bool insert(int item); //默认往尾部插入
	int get(int location); //获取
	int  insertWithSort(int item); //有序插入
	int  length();   //返回长度
	bool full();
	bool empty();
	void clear();
	void randInsert(int range); //随机插入数
	int  search(int item);//顺序查找
	int  binarySearch(int item); //二分查找
	bool del(int data); //删除某个数据
	bool delLocation(int p);

	void bubbleSort();   //冒泡排序
	void doubleWayBubbleSort(); //双向冒泡排序
	void RecQuickSort(int low, int high); //快速排序递归版
	void quickSort();    //快速排序非递归版
	void selectSort();   //选择排序
	void insertSort(int low,int high);   //插入排序
	void binaryInsertSort(); //折半插入排序
	void mergeSort(int low,int high);    //归并排序
	void shellSort();    //希尔排序(缩小增量)
	void heapSort();     //堆排序
	 

	void traverse();     //打印
	void test(int times, int range);
private:
	int *sequence;
	int Sequence_length;  //长度
	int Sequence_capacity;
	void swap(int &a, int &b);
	void merge(int low, int mid,int high); //两个有序数组的合并
	void createHeap();
	void headpAjust(int s, int m); //s为跟节点 m为长度
};
#endif