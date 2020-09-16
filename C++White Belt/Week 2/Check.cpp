bool IsPalindrom(string word) {
	string check;
	for (int i = word.size()-1; i >= 0; i--) {
		check+= word[i];
	}
	if (check == word)
		return true;
	else
		return false;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector <string> check;
	for (auto c : words) {
		if (IsPalindrom(c) == 1 && c.size() >= minLength) {
			check.push_back(c);
		}
	}
	return check;
}