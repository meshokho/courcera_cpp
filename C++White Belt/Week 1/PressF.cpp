#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	cin >> a;
	int k = -2;
	int i = 0;
	for (auto x : a) {
		if (x == 'f') {
			k++;
			if (k == 0) {
				cout << i;
				return 0; 
			}
		}
		i++;
	}
	cout << k;
	return 0;
}