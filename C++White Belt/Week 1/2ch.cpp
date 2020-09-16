#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int> num;
	cin >> n;
	while (n > 0) {
		num.push_back(n%2);
		n = n / 2;
	}
	for (int i = num.size() - 1; i > -1; --i) {
		cout << num[i];
	}
	return 0;
} 