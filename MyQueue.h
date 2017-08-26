#ifndef	MYQUEUE_H
#define MYQUEUE_H
class MyQueue {
public:
	MyQueue(int capacity);		 //���캯�� ��������
	~MyQueue();					 //�������� ���ٶ���
	void clear();				 //��ն���
	bool empty() const;			 //�ж϶����Ƿ�Ϊ��
	bool full() const;			 //�ж϶����Ƿ�Ϊ��
	int  length() const;			 //��ȡ���г���
	int  getHead();			    //��ȡ��ͷԪ��
	int  getTail();                 //��ȡ��βԪ��
	int  getItem(int position);   //��ȡ�����е�i��λ�õ�Ԫ��
	bool enqueue(int item);			 //���
	int dequeue();			 //����
	void traverse();		 //����
private:
	int *queue;                      //��������ָ��
	int queue_length;				  //���г���					
	int queue_capacity;             //��������
	int head;
	int tail;
};

#endif