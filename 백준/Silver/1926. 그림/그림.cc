#include<iostream>
#include<string>
#include <algorithm>

using namespace std;
int map[500][500];
int visited[500][500];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int m, n, width=1;
int cnt = 0, maxArea = 0;
void dfs(int y, int x) {

	visited[y][x] = 1;
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (map[ny][nx] == 1 && visited[ny][nx] == 0) {
			visited[ny][nx] = 1;
			width++;
			dfs(ny, nx);
		}

	}

}
int main() {

	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> map[y][x];
		}
	}
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (!visited[y][x] && map[y][x]==1) {
				cnt++;
				width= 1;
				dfs(y, x);
				maxArea = max(maxArea, width);
				
			}
		}
	}

	cout << cnt << '\n';
	cout << maxArea << '\n';
	
	return 0;
}