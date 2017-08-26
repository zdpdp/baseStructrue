#ifndef	MYQUEUE_H
#define MYQUEUE_H
class MyQueue {
public:
	MyQueue(int capacity);		 //构造函数 传入容量
	~MyQueue();					 //析构函数 销毁对象
	void clear();				 //清空队列
	bool empty() const;			 //判断队列是否为空
	bool full() const;			 //判断队列是否为满
	int  length() const;			 //获取队列长度
	int  getHead();			    //获取对头元素
	int  getTail();                 //获取对尾元素
	int  getItem(int position);   //获取队伍中第i个位置的元素
	bool enqueue(int item);			 //入队
	int dequeue();			 //出队
	void traverse();		 //遍历
private:
	int *queue;                      //队列数组指针
	int queue_length;				  //队列长度					
	int queue_capacity;             //队列容量
	int head;
	int tail;
};

#endif