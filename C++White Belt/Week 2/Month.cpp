#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Add(vector<vector<string>>& month, string delo, int day) 
{
	month[day-1].push_back(delo);
}

void Dump(vector<vector<string>>& month, int day)
{
	cout << month[day - 1].size() << " ";
	for (auto c : month[day - 1]) {
		cout << c << " ";
	}
	cout << endl;
}

void Next(vector<vector<string>>& month, const vector<int>& days_in_month, int& k) {
	const int old = days_in_month[k];
	k = (k + 1) % 12;
	const int newl = days_in_month[k];
	if (newl < old) {
		vector<string>& last_day = month[newl - 1];
		for (int day = newl; day < old; ++day) {
			last_day.insert(
				end(last_day),
				begin(month[day]), end(month[day]));
		}
	}
	month.resize(newl);
}

int main()
{
	int q;
	cin >> q; //Количество операций.

	vector <int> days_in_month = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int k = 0;

	vector<vector<string>> cur_month(31);

	for (int i = 0; i < q; i++) {
		string act;
		cin >> act;

		if (act == "ADD") {
			int day;
			cin >> day;
			string delo;
			cin >> delo;
			Add(cur_month, delo, day);
		}
		else if (act == "DUMP") {
			int day;
			cin >> day;
			Dump(cur_month, day);
		}
		else if (act == "NEXT") {
			Next(cur_month, days_in_month, k);
		}
	}

	return 0;
}

