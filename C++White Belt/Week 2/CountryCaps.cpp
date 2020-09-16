#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int q;
	cin >> q;

	map <string, string> councap;

	for (int i = 0; i < q; i++) {
		string operation;
		cin >> operation;

		if (operation == "CHANGE_CAPITAL") {
			string country, new_cap;
			cin >> country >> new_cap;
			if (councap.count(country) == 0) {
				cout << "Introduce new country " << country << " with capital " << new_cap << endl;
			}
			else {
				const string& old_cap = councap[country];
				if (old_cap == new_cap) {
					cout << "Country " << country << " hasn't changed its capital" << endl;
				}
				else {
					cout << "Country " << country << " has changed its capital from " << old_cap << " to " << new_cap << endl;
				}
			}
			councap[country] = new_cap;
		}
		else if (operation == "RENAME") {
			string oldname, newname;
			cin >> oldname >> newname;
			if (oldname == newname || councap.count(oldname) == 0 || councap.count(newname) == 1) {
				cout << "Incorrect rename, skip" << endl;
			}
			else {
				cout << "Country " << oldname << " with capital " << councap[oldname] <<
					" has been renamed to " << newname << endl;
				councap[newname] = councap[oldname];
				councap.erase(oldname);
			}
		}
		else if (operation == "ABOUT") {

			string country;
			cin >> country;
			if (councap.count(country) == 0) {
				cout << "Country " << country << " doesn't exist" << endl;
			}
			else {
				cout << "Country " << country << " has capital " << councap[country] << endl;
			}
		}
		else if (operation == "DUMP") {
			if (councap.empty()) {
				cout << "There are no countries in the world" << endl;
			}
			else {
				for (const auto& country_item : councap) {
					cout << country_item.first << "/" << country_item.second << " ";
				}
				cout << endl;
			}
		}


	}
	return 0;
}