#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void PrintAllBuses(const map<string, vector<string>>& buses) {
	if (buses.size() == 0) {
		cout << "No buses" << endl;
	}
	else {
		for (const auto& bus : buses) {
			cout << "Bus " << bus.first << ": ";
			for (const auto& stop : bus.second) {
				cout << stop << " ";
			}
			cout << endl;
		}
	}
}
void PrintBusVector(const vector<string>& buses) {
	if (buses.size() == 0) {
		cout << "No stop" << endl;
	}
	else {
		for (const auto& b : buses) {
			cout << b << " ";
		}
		cout << endl;
	}
}
void PrintBusVectorWithout(const vector<string>& buses_on_stop, const string& bus_num) {
	vector<string> buses_on_stop_without;
	for (const auto& b : buses_on_stop) {
		if (b != bus_num) {
			buses_on_stop_without.push_back(b);
		}
	}
	if (buses_on_stop_without.size() == 0) {
		cout << "no interchange" << endl;
	}
	else {
		for (const auto& b : buses_on_stop_without) {
			cout << b << " ";
		}
		cout << endl;
	}
}
vector<string> BusesForStop(vector<string>& b, const map<string, vector<string>>& buses, const string& stop) {
	vector<string> bus;
	vector<string> b_tmp;

	for (const auto& item : buses) {
		for (const auto& find_stop : item.second) {
			if (find_stop == stop) {
				bus.push_back(item.first);
			}
		}
	}
	for (const auto& i : b) {
		int n = 0;
		n = count(begin(bus), end(bus), i);
		if (n != 0) {
			b_tmp.push_back(i);
		}
	}
	return b_tmp;
}

void StopsForBuses(vector<string>& b, const map<string, vector<string>>& buses, const string& bus_num) {
	vector<string> buses_on_stop;
	for (auto& item : buses) {
		if (item.first == bus_num) {
			for (auto& stop : item.second) {
				cout << "Stop " << stop << ": ";
				buses_on_stop = BusesForStop(b, buses, stop);
				PrintBusVectorWithout(buses_on_stop, bus_num);
			}
		}
	}
}


int main()
{
	int q, count;
	string operation, busnum, stop;

	map<string, vector<string>> buses;
	vector<string> bus;
	vector<string> b;
	cin >> q;

	for (int i = 0; i < q; ++i) {
		cin >> operation;
		if (operation == "NEW_BUS") {
			cin >> busnum >> count;
			b.push_back(busnum);
			for (int i = 0; i < count; ++i) {
				cin >> stop;
				buses[busnum].push_back(stop);
			}
		}
		if (operation == "BUSES_FOR_STOP") {
			cin >> stop;
			bus = BusesForStop(b, buses, stop);
			PrintBusVector(bus);
		}
		if (operation == "STOPS_FOR_BUS") {
			cin >> busnum;
			if (buses.count(busnum) == 0) {
				cout << "No bus" << endl;
			}
			else {
				StopsForBuses(b, buses, busnum);
			}
		}
		if (operation == "ALL_BUSES") {
			PrintAllBuses(buses);
		}
	}
	return 0;
}