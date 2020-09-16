void MoveStrings(vector<string>& source, vector<string>& destination) {
	for (auto c : source) {
		destination.push_back(c);
	}
	source.clear();
}