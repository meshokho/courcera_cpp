#include <iostream>
using namespace std;

int main()
{
	double n, a, b, x, y;
	cin >> n >> a >> b >> x >> y;
	if (n <= a) {
		cout << n;
		return 0;
	}
	if (n > b) {
		cout << n - n * 0.01*y;
	}
	else if (n > a) {
		cout << n - n * 0.01*x;
	}
	return 0;
}