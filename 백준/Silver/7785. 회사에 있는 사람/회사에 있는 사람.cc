#include <iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
map<string, int> m;
vector<string>s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;

	cin >> n;
	string name, p;
	for (int i = 0; i < n; i++) {
		cin >> name >> p;
		if (p == "leave")m[name] = 0;
		else m[name] = 1;
	}
	for (auto v : m) {
		if (v.second)s.push_back(v.first);
	}
	sort(s.rbegin(), s.rend());
	for (auto v : s) cout << v << "\n";
	return 0;
}