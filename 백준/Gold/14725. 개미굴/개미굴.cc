#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int N;
typedef struct Trie {
	map<string, Trie*> mp;
	map<string, Trie*>::iterator iter;

	void insert(vector<string> str, int depth) {
		if (depth == str.size()) {
			return;
		}

		string s = str[depth];
		iter = mp.find(s);

		// 없는 경우
		if (iter == mp.end()) {
			Trie* newTrie = new Trie();
			mp.insert({s, newTrie});
			mp[s]->insert(str, depth+1);
		}
		else { // 있는 경우
			iter->second->insert(str, depth + 1);
		}
	}

	void print(int depth) {
		// 없는 경우
		if (mp.empty()) return;
		
		for (auto it = mp.begin(); it != mp.end(); it++) {
			// depth만큼 출력
			for (int i = 0; i < depth; i++) cout << "--";
			cout << it->first << '\n';
			it->second->print(depth + 1);
		}
	}
}Trie;
int main() { // Trie
	cin >> N;
	Trie* root = new Trie();
	for (int i = 0; i < N; i++) {
		vector<string> v;
		int k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			string s;
			cin >> s;
			v.push_back(s);
		}
		root->insert(v, 0);
	}

	// 출력
	root->print(0);
	return 0;
}
/*
4
2 KIWI BANANA
2 KIWI APPLE
2 APPLE APPLE
3 APPLE BANANA KIWI
*/