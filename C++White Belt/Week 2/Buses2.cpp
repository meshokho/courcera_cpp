#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int q;
	cin >> q;

	map<vector<string>, int> buses_stations;
	vector<string> stations;
	vector<string> a;
	int newv;
	int lastv = -1;

	for (int i = 0; i < q; i++) {
		int n;
		cin >> n;
		a.clear();

		for (int k = 0; k < n; k++) {
			string stop;
			cin >> stop;
			a.push_back(stop);
		}
		if (buses_stations.count(a) == 0) {
			newv = buses_stations.size() + 1;
			buses_stations[a] = newv;
			cout << "New bus " << newv << endl;
		}
		else {
			cout << "Already exists for " << buses_stations[a] << endl;
		}
	}
	return 0;
}