#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(string word){
	string check = '';
	for (int i = word.length(); i > 0; i--) {
		check.append(word[i]);
	}
	if (check == word)
		return True;
	else
		return False;
}

int main()
{
	string a;
	cin >> a;
	cout << IsPalindrom(a);
	return 0;
}
