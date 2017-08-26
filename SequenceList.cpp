#include "SequenceList.h"
#include<iostream>
#include <time.h>  
#include "MyStack.h"

using namespace std;
SequenceList::SequenceList(int capacity) {
	Sequence_capacity = capacity;
	sequence = new int[Sequence_capacity];
	Sequence_length = 0;
}
SequenceList::~SequenceList() {
	delete []sequence;
	sequence = nullptr;
}
bool SequenceList::del(int data) {
	int location=-1;
	for (int i = 0; i < length(); i++) {
		if (sequence[i] == data) {
			location = i;
		}
	}
	if (delLocation(location)) {
		return true;
	}
	else {
		return false;
	}
}
bool SequenceList::delLocation(int p) {
	if (p<0 || p>length() - 1)
		return false;
	for (int i = p; i < length()-1; i++) {
		sequence[i] = sequence[i + 1];
	}
	Sequence_length--;
	return true;
}
bool SequenceList::insert(int item, int position) {
	if (position<0 || position>Sequence_length+1||full()) {
		return false;
	}
	for (int i = Sequence_length; i >= position; i--) {
		sequence[i + 1] = sequence[i];
	}
	sequence[position] = item;
	Sequence_length++;
	return true;
}
bool SequenceList::insert(int item) {
	//数组尾部插入
	if (full()) {
		return false;
	}
	sequence[Sequence_length] = item;
	Sequence_length++;
	return true;
}
bool SequenceList::full() {
	return Sequence_length == Sequence_capacity ? true : false;
}
bool SequenceList::empty() {
	return Sequence_length == 0 ? true: false;
}
int SequenceList::length() {
	return Sequence_length;
}
void SequenceList::randInsert(int range) {
	int num = Sequence_capacity;
	if (Sequence_length + num <= Sequence_capacity) {
		srand((unsigned)time(NULL));
		for (int i = 0; i < num; i++) {
			sequence[Sequence_length++] = rand() % range;
		}
	}
	else {
		throw "超出顺序表大小限制";
	}
}
int SequenceList::insertWithSort(int item) {
	//有序插入 返回插入位置
	if (full()) {
		return -1;
	}
	for (int i = 0; i < Sequence_length; i++) {
		if (sequence[i] > item) {
			continue;
		}
		else {
			insert(item, i);
			return i;
		}
	}
	
	insert(item);
	return Sequence_length - 1;

}
int SequenceList::search(int item) {
	//返回第一个查找到的位置 -1没查找到
	for (int i = 0; i < Sequence_length; i++) {
		if (sequence[i] == item) {
			return i;
		}
	}
	return -1;
}
int SequenceList::binarySearch(int item) {
	//默认为升序
	int first = 0;
	int last = Sequence_length - 1;
	while (first <= last) {
		int mid = (first + last) / 2;
		if (sequence[mid] == item) {
			return mid;
		}
		if (sequence[mid] > item) {
			last = mid - 1;
		}
		else {
			first = mid + 1;
		}
	}
	return -1;
}
void SequenceList::bubbleSort() {
	//冒泡排序 最好情况 0n 最坏情况On2
	bool flag; //是否发生交换的标志
	for (int i = 0; i < Sequence_length-1; i++) {
		flag = false;
		for (int j = 0; j < Sequence_length-1-i; j++) {

			if (sequence[j] > sequence[j + 1]) {
				swap(sequence[j], sequence[j + 1]);
				flag = true; 
			}

		}
		if (!flag) {
			//上一轮没有发生任何交换，说明现在是有序的 提前结束
			break;
		}
	}
}
void SequenceList::doubleWayBubbleSort() {
	
	bool flag = true;; //是否发生交换的标志
	int left = 0;
	int right = Sequence_length-1;
	while(left<right&&flag){
		flag = false;
		for (int i = left; i < right; i++) {
			if (sequence[i] > sequence[i + 1]) {
				swap(sequence[i], sequence[i + 1]);
				flag = true;
			}
			
		}
		right--;
		for (int i = right; i > left; i--) {
			if (sequence[i] < sequence[i - 1]) {
				swap(sequence[i], sequence[i - 1]);
				flag = true;
			}
			
		}
		left++;
	}
}
void SequenceList::selectSort() {
	//选择排序 On2
	int key;
	for (int i = 0; i < Sequence_length; i++) {
		key = i;
		for(int j = i+1; j < Sequence_length;j++){
			if (sequence[j] < sequence[key]) {
				key = j;
			}
		}
		//选出最小的元素 与 i位置的元素交换
		swap(sequence[i], sequence[key]);

	}
}
void SequenceList::RecQuickSort(int first,int last) {
	//递归版的快排
	if (first > last) {
		return;
	}
	int low = first;
	int high = last;
	int key = sequence[low];
	while (low < high) {
		
		for (int i = high; i > low; i--) {	
		
			if (sequence[i] < key) {
				swap(sequence[i], sequence[low]);
				break;
			}
			high--;
		
		
		}
		for (int i = low; i < high; i++) {	
		
			if (sequence[i] > key) {
				swap(sequence[i], sequence[high]);
				break;
			}
			low++;
			
		}

	}
	sequence[low] = key;
	RecQuickSort(first, high - 1);
	RecQuickSort(low+1, last);
	
}
void SequenceList::quickSort() {
	//非递归版的快排 利用栈模拟
	int num = log2(length());
	MyStack *p = new MyStack(num+10);
	int first = 0;
	int last = length() - 1;
	int high, low, key;
	p->push(first);
	p->push(last);
	while (!p->empty()) {
		high = p->pop();
		last = high;
		low = p->pop();
		first = low;
		if (low >= high) {
			continue;
		}
		key = sequence[low];
		while (low < high) {
			for (int i = high; i > low; i--) {
				if (sequence[i] < key) {
					swap(sequence[i], sequence[low]);
					break;
				}
				high--;
			}
			for (int i = low; i < high; i++) {
				if (sequence[i] > key) {
					swap(sequence[i], sequence[high]);
					break;
				}
				low++;
			}
		}
		sequence[low] = key;
		
		p->push(low + 1);
		p->push(last);
		p->push(first);
		p->push(high - 1);
	}
	delete p;
	p = nullptr;
}
void SequenceList::traverse() {
	int i = 5;//每行显示五个
	for (int i = 0; i < Sequence_length; i++) {
		cout << sequence[i] << "\t";
		if ((i+1) % 5 == 0) {
			cout << endl;
		}
	}
	cout << endl;
}
void SequenceList::clear() {
	Sequence_length = 0;
}
void SequenceList::swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
void SequenceList::test(int times,int range) {
	clock_t startTime, endTime;
	double selectsum = 0;
	double bubblesum = 0;
	double DoubleBubblesum = 0;
	double RecQuicksum = 0;
	double Quicksum = 0;
	for (int i = 0; i < times; i++) {

		randInsert(range);
		startTime = clock();
		this->selectSort();
		endTime = clock();
		clear();
		selectsum +=(double)(endTime - startTime) ;


		randInsert(range);
		startTime = clock();
		this->bubbleSort();
		endTime = clock();
		clear();
		bubblesum += (double)(endTime - startTime);


		randInsert(range);
		startTime = clock();
		this->doubleWayBubbleSort();
		endTime = clock();
		clear();
		DoubleBubblesum += (double)(endTime - startTime);

		randInsert(range);
		startTime = clock();
		this->RecQuickSort(0, length() - 1);
		endTime = clock();
		clear();
		RecQuicksum += (double)(endTime - startTime);

		randInsert(range);
		startTime = clock();
		this->quickSort();
		endTime = clock();
		clear();
		Quicksum += (double)(endTime - startTime);
	}
	cout << "选择排序" << times  <<"次运行时长：" << selectsum << "ms" << endl;
	cout << "单向冒泡" << times << "次运行时长："<<bubblesum << "ms" << endl;
	cout << "双向冒泡" << times << "次运行时长："<< DoubleBubblesum << "ms" << endl;
	cout << "递归快排" << times << "次运行时长：" << RecQuicksum << "ms" << endl;
	cout << "非递归快排" << times << "次运行时长：" << Quicksum << "ms" << endl;

}
void SequenceList::insertSort(int low,int high) {
	int key, temp;
	for (int i = low+1; i <= high; i++) {
		if (sequence[i] < sequence[i-1]) {
			key = sequence[i];
			temp = i;
			while (sequence[temp-1] > key) {
				sequence[temp] = sequence[temp-1];
				temp--;
			}
			sequence[temp] = key;
		}

	}
}
void SequenceList::binaryInsertSort() {
	//折半插入排序
	int key, temp, first,last,mid;
	for (int i = 1; i < length(); i++) {
		if (sequence[i] < sequence[i - 1]) {
		
			key = sequence[i];
			//二分查找区间
			first = 0;
			last = i-1;
			
			while(first<=last){
				mid = (first + last) / 2;
				if (key < sequence[mid]) {
					last = mid - 1;  //查找区间在前半段
				}
				else {
					first = mid + 1; //查找区间在后半段
				}
				
			}
			for (int y = i; y > mid; y--) {
				sequence[y] = sequence[y-1];
			}
		
			sequence[last+1] = key;
		
		}

	}
}
void SequenceList::mergeSort(int low, int high) {
	if (low >= high)
		return;
	int mid = (low + high) / 2;
	mergeSort(low, mid);
	mergeSort(mid + 1, high);
	merge(low,mid, high);
}
void SequenceList::merge(int low,int mid ,int high) {

	int s, t,i=0;
	s = low;
	t = mid + 1;
	int *p = new int[high - low + 1];
	while (s <= mid&&t <= high) {
		if (sequence[s] <= sequence[t]) {
			p[i] = sequence[s];
			s++;
		}
		else {
			p[i] = sequence[t];
			t++;
		}
		i++;
	}
	while (s <= mid) {
		p[i++] = sequence[s++];
	}
	while (t <= high) {
		p[i++] = sequence[t++];
	}
	i = 0;
	for (int j = low; j <= high; j++,i++) {
		sequence[j] = p[i];
	}
	delete []p;
	p = nullptr;
}
void SequenceList::shellSort() {
	int d = length() / 2;
	while (d >= 1) {
		for (int i = 0; i + d < length();i++) {
			insertSort(i, i + d );
		}
		d = d / 2;
	}
}
void SequenceList::heapSort() {
	// 交换  堆调整
	createHeap(); //建初堆
	for (int i = length()-1; i > 0; i--) {
			swap(sequence[i], sequence[0]);
			headpAjust(0, i - 1);
	}
}
void SequenceList::createHeap() {
	int n = (length()-1) / 2;
	cout << "n:" << n << endl;
	
	//左节点 2n+1 右节点 2n+2
	for (int i = n; i >=0; i--) {
		headpAjust(i, Sequence_length - 1);
	}
	
	 

}
void SequenceList::headpAjust(int s,int m) {
	//调整为s为跟节点 数组总长度为m的序列成为最大堆
	int key = sequence[s];

	for (int j = 2 * s + 1; j <= m; j = j*2+1) {
		if (j < m&& sequence[j] < sequence[j + 1]) {
			j++; //j记录 左右子节点中较大的一个
		}
		if (key >= sequence[j])
			break;
		sequence[s] = sequence[j]; 
		s = j;
	}
	sequence[s] = key;

}
int  SequenceList::get(int location) {
	if (location < 0 || location>length() - 1) {
		return NULL;
	}
	else {
		return sequence[location];
	}
}