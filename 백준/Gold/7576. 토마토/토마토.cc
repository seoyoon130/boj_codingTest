#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int map[1001][1001];
int m, n;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int dist[1001][1001];
queue<pair<int, int>> q;
void bfs() {
	while (!q.empty()) {
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (dist[ny][nx] >= 0)continue;
			dist[ny][nx] = dist[curY][curX] + 1;
			q.push({ ny, nx });
		}

	}
	
}
int main() {
	cin >> m >> n;
	
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> map[y][x];
			if (map[y][x] == 1) {
				q.push({ y, x });
			}
			if (map[y][x] == 0) {
				dist[y][x] = -1;
			}
		}
	}

	bfs();
	int cnt = 0;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (dist[y][x] == -1) {
				cout << "-1";
				return 0;
			}
			cnt = max(cnt, dist[y][x]);
		}
	}
	cout << cnt;
	return 0;

}