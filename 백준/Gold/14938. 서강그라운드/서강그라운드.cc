#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 101
#define INF 987654321
using namespace std;
int item[MAX];
int dist[MAX];
vector<pair<int, int > > v[MAX];
int n, m, r;
void search(int start){
    queue<int> q;
    for(int i = 1;i<=n;i++){
        dist[i] = INF;
    }
    //낙하지점까지의 거리는 0이므로, 
    //queue에 미리 start를 넣어준다.
    dist[start] = 0;
    q.push(start);

    //queue를 하나씩 탐색해주면서
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i = 0;i<v[node].size();i++){
            int next = v[node][i].first;
            int weight = v[node][i].second;

            //최단 경로라면, 큐에 다시 넣어준다
            if(dist[node] + weight <dist[next]){
                dist[next] = dist[node]+weight;
                q.push(next);
            }
        }
    }
}
int main(){
    cin >> n >> m >> r;
    for(int i = 1;i<=n;i++){
        cin >> item[i];
    }
    //각 구역의 길의 길이 저장해주기
    for(int i = 0;i<r;i++){
        int a, b, l;
        cin >> a >> b >> l;
        v[a].push_back({b, l});
        v[b].push_back({a, l});        
    }
    //아이템 수
    int res = 0;
    for(int i = 1;i<=n;i++){
        search(i);
        int sum = 0;
        for(int i = 1;i<=n;i++){
            //수색 범위보다 작거나 같다면
            if(dist[i] <= m){
                sum += item[i];
            }
        }
        res = max(res, sum);
    }
    cout << res;
    return 0;
}