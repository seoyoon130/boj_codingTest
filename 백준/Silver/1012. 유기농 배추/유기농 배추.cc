#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int T;
int m, n, k;
int y, x;
bool visited[51][51];
int map[51][51];
queue<pair<int, int>> q;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
void bfs(int x, int y) {
	visited[x][y] = 1;
	q.push({x, y });
	
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
			if (map[nx][ny] !=1 ||visited[nx][ny] == 1) continue;
			visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
}
int main() {
	
	cin >> T;
	while (T--) {
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			map[y][x] = 1;
		}
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
		for (int i = 0; i < n; i++) {
			fill(map[i], map[i] + m, 0);
			fill(visited[i], visited[i] + m, false);
		}
	}
	
	return 0;

}