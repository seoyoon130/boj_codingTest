#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
queue<pair<int, int>> q;
bool visited[200001];
int n, k;
void bfs() {
	q.push({ n, 0 });
	visited[n] = 0;
	while (!q.empty()) {
		int pos = q.front().first;
		int time = q.front().second;
		q.pop();
		//범위를 벗어나면
		if (pos < 0 || pos>100000) continue;
		if (pos == k) {
			cout << time;
			break;
		}
		if (visited[pos * 2] == false) {
			visited[pos * 2] = true;
			q.push({ pos * 2, time + 1 });
		}
		if (visited[pos - 1] == false) {
			visited[pos - 1] = true;
			q.push({ pos - 1, time + 1 });
		}
		if (visited[pos+1] == false) {
			visited[pos + 1] = true;
			q.push({ pos + 1, time + 1 });
		}
	}
}
int main() {
	cin >> n >> k;
	bfs();
	return 0;

}