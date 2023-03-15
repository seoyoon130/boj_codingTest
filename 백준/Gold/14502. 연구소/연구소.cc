#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int a[10][10];
int b[10][10];
queue<pair<int, int>> q;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
//안전한 영역 구하기 -> 최소로 탐색되고 싶으므로 bfs를 돌리기

void dfs(int x, int y) {
    for (int k=0; k<4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            if (b[nx][ny] == 0) {
                b[nx][ny] = 2;
                dfs(nx,ny);
            }
        }
    }
}
//dfs를 이용해 
//벽을 3개 세워준다
int dfs() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            b[i][j] = a[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (b[i][j] == 2) {
                dfs(i, j);
            }
        }
    }
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (b[i][j] == 0) {
                cnt += 1;
            }
        }
    }
    return cnt;
}
int main(){   
    cin >> n >> m;
    for(int y = 0;y<n;y++){
        for(int x = 0;x<m;x++){
            cin >> a[y][x];
        }
    }
    int ans = 0;
    for (int x1=0; x1<n; x1++) {
        for (int y1=0; y1<m; y1++) {
            if (a[x1][y1] != 0) continue;
            for (int x2=0; x2<n; x2++) {
                for (int y2=0; y2<m; y2++) {
                    if (a[x2][y2] != 0) continue;
                    for (int x3=0; x3<n; x3++) {
                        for (int y3=0; y3<m; y3++) {
                            if (a[x3][y3] != 0) continue;
                            if (x1 == x2 && y1 == y2) continue;
                            if (x1 == x3 && y1 == y3) continue;
                            if (x2 == x3 && y2 == y3) continue;
                            a[x1][y1] = 1;
                            a[x2][y2] = 1;
                            a[x3][y3] = 1;
                            int cur = dfs();
                            if (ans < cur) ans = cur;
                            a[x1][y1] = 0;
                            a[x2][y2] = 0;
                            a[x3][y3] = 0;
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}