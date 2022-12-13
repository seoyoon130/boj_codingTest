#include <iostream>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	int vect[100000] = { 0 };
	cin >> n >> m;
	int en = 0;
	int ans = 0x7fffffff;
	for (int i = 0; i < n; i++) {
		cin >> vect[i];
	}
	sort(vect, vect + n);
	for (int st = 0; st < n; st++) {
		while (en < n && vect[en] - vect[st] < m) en++;
		if (en == n) break;
		ans = min(ans, vect[en] - vect[st]);
	}
	cout <<ans << "\n";
	return 0;
}