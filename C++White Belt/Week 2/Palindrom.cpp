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