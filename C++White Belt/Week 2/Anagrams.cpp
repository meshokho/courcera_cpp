#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(string word) {
	map<char, int> chars;
	for (const auto& c : word) {
		++chars[c];
	}
	return chars;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string word1;
		string word2;
		cin >> word1 >> word2;
		if (BuildCharCounters(word1) == BuildCharCounters(word2)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
