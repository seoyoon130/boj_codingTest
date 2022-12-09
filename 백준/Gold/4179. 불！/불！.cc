#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
char map[1002][1002];
int r, c;

queue<pair<int, int>> fire;
queue<pair<int, int>> jh;
int timeFire[1002][1002];
int timeJh[1002][1002];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main() {
	cin >> r >> c;
	//vis 배열 대신, timeFire/timeJh 에 -1로 초기화해준다.
	for (int i = 0; i < r; i++) {
		fill(timeFire[i], timeFire[i] + c, -1);
		fill(timeJh[i], timeJh[i] + c, -1);
	}
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'F') {
				fire.push({ y, x });
				timeFire[y][x] = 0;
			}
			if (map[y][x] == 'J') {
				jh.push({ y, x });
				timeJh[y][x] = 0;
			}
		}
	}
	//불이 난 위치에서 bfs를 돌리고
	//시간을 저장해준다. 
	while (!fire.empty()) {

		int curY = fire.front().first;
		int curX = fire.front().second;
		fire.pop();
		for (int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (map[ny][nx] == '#' || timeFire[ny][nx] >= 0)continue;
			timeFire[ny][nx] = timeFire[curY][curX] + 1;
			fire.push({ ny, nx });

		}
	}
	while (!jh.empty()) {
		int curY = jh.front().first;
		int curX = jh.front().second;
		jh.pop();
		for (int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];
			//탈출에 성공!
			if (nx < 0 || ny < 0 || ny >= r || nx >= c) {
				cout << timeJh[curY][curX] + 1;
				return 0;
			}
			if (timeJh[ny][nx] >= 0 || map[ny][nx] == '#') continue;
			if (timeFire[ny][nx] != -1 && timeFire[ny][nx] <= timeJh[curY][curX] + 1) continue;
			timeJh[ny][nx] = timeJh[curY][curX] + 1;
			jh.push({ ny, nx });
		}
	}
	cout << "IMPOSSIBLE";
	return 0;

}