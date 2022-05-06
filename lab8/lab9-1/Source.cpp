#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <queue>

typedef std::pair<std::string, int> key_value;

int main() {

	unsigned i = 0;

	std::ifstream fin("Text.txt");
	if (!fin.is_open()) {
		printf("Failed to open the file.");
		return -1;
	}

	std::string string, buffer, separators = " ,.!?";
	std::map<std::string, int> map;
	std::getline(fin, string);

	//turning case-insensitive
	while (string[i] != '\0') {
		if (string[i] < 'a' && string[i] >= 'A')
			string[i] += 32;
		i++;
	}
	i = 0;
	while (string[i] != '\0') {

		while (separators.find(string[i]) == std::string::npos) {
			buffer.push_back(string[i]);
			i++;
		}

		map[buffer]++;
		buffer.clear();

		while (separators.find(string[i]) != std::string::npos)
			i++;
	}
	auto cmp = [](const key_value& a, const key_value& b) {
		if (a.second != b.second)
			return a.second < b.second;
		return a.first > b.first;
	};
	std::priority_queue<key_value, std::vector<key_value>, decltype(cmp)> q(map.begin(), map.end(), cmp);

	while (!q.empty()) {
		key_value top = q.top();
		std::cout << top.first << " => " << top.second << '\n';
		q.pop();
	}

	return 420;
}