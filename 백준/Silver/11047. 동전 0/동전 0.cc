#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> s;
	int num, cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		s.push_back(num);
	}
	while (k != 0){
		if (s.back() > k) {
			s.pop_back();
		}
		else if (s.back() <= k) {
			cnt += k / s.back();
			k = k % s.back();
		}
	}
	cout << cnt;
	return 0;
}