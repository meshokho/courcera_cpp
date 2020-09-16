#include <iostream>
#include <string>
#include <vector>
using namespace std;

int worry_count(const vector<bool>& queue) {
	int k = 0;
	for (auto c : queue) {
		if (c == true) {
			k++;
		}
	}
	return k;
}

void QueueAct(vector<bool>& queue, string act, int num) {
	if (act == "COME") {
		for (int i = 0; i < num; i++) {
			queue.resize(queue.size()+num);
		}
	}
	if (act == "WORRY") {
		queue[num] = true;
	}
	if (act == "QUIET") {
		queue[num] = false;
	}
}

int main()
{
	int q;
	cin >> q;

	vector<bool> queue;

	for (int i = 0; i < q; i++) {
		string act;
		int num;
		cin >> act;
		if (string == "WORRY_COUNT") {
			cout << worry_count(queue);
		}
		else {
			cin >> num;
			QueueAct(queue, act, num);
		}
	}

	return 0;
}
