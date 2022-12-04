#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
string str;
int map[101][101];
int n, m;
int dy[4] = {-1, 1, 0,0};
int dx[4] = { 0, 0, -1, 1 };
int dist[102][102];
queue<pair<int, int>> q;
void bfs(int y, int x) {

	q.push({ y,x });
	dist[y][x] = 0;
	while (!q.empty()) {
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (map[ny][nx]!=1||dist[ny][nx]>=0) continue;
			dist[ny][nx] = dist[curY][curX] + 1;
			q.push({ ny, nx });
			
		}
	}
	cout << dist[n-1][m- 1]+1;

}
int main() {
	
	cin >> n >> m;
	
	for (int y = 0; y < n; y++) {
		cin >> str;
		for (int x = 0; x < m; x++) {
			map[y][x] = str[x] - '0';
		}
	}
	//#1. 거리를 저장할 dist 칸들을 -1로 초기화
	for (int i = 0; i < n; i++) {
		fill(dist[i], dist[i] + m, -1);
	}
	bfs(0, 0);
	
	return 0;

}