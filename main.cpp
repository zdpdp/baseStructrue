#include<iostream>
#include "MyQueue.h";
#include "SequenceList.h"
#include "MyStack.h"
#include "LinkList.h"
#include "MyGraph.h"
#include <time.h>
#include <vector>
#include<cmath>
#include<stack>
#include<string>
#include<list>
#include<algorithm>
#include<queue>
#include<deque>
#include "BinaryTree.h"
using namespace std;

int main() {
	int count, x;;
	cin >> count;
	vector<int> arr;
	vector<int> res;
	for (int i = 0; i<count; i++) {
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	int sum = 0;
	int a = 0, i = 0, j = count - 1;
	while (a<count) {
		if (a % 2 == 0) {
			res.push_back(arr[j]);
			j--;
		}
		else {
			res.push_back(arr[i]);
			i++;
		}
		a++;
	}
	for (int i = 0; i<count - 1; i++) {
		sum += abs(res[i] - res[i + 1]);
	}
	cout << sum;
}
