#include <iostream>
#include<vector>
#include<queue>
#include <string.h>
#include<algorithm>
using namespace std;
vector<int> graph[1001];
bool visited[1001];
//넥스트, 방문여부 확인
void dfs(int idx) {
    visited[idx] = true;
    cout << idx<< " ";
    for (int i = 0; i<graph[idx].size(); i++) {
        //다음 인접 리스트를 확인해서
        int next = graph[idx][i];
        //만약 방문하지 않은 노드라면
        if (!visited[next]) dfs(next);
    }
}
//큐에서 하나씩 빼주면서 
void bfs(int idx) {
    queue<int>q;
    q.push(idx);
    memset(visited, false, sizeof(visited));
    visited[idx] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << now << " ";

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, v;
    cin >> n >> m >> v;
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        
    }
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(v);
    cout << "\n";
    bfs(v);
}