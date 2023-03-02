#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 987654321

using namespace std;
int n, m, x;
int s, e, t;
vector<pair<int, int> > map[MAX];
int d[MAX];
int dijsktra(int start){
    //미리 거리를 저장해주는 배열을 초기화 시켜준다.
    for(int i = 1;i<=n;i++){
        d[i] = INF;
    }
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(-0, start));
    d[start] = 0;

    while(!pq.empty()){
        int cur_w = -pq.top().first;
        int cur_n = pq.top().second;
         
        pq.pop();
        for(int i = 0;i<map[cur_n].size();i++){
            int next_n = map[cur_n][i].first;
            int next_w = map[cur_n][i].second;

            if(d[next_n] > cur_w + next_w){
                d[next_n] = cur_w+next_w;
                pq.push(make_pair(-d[next_n], next_n));

            }
        }
    }
    return d[x];
}

int main(){
    int result = 0;
    cin >> n >> m >> x;
    for(int i = 0;i<m;i++){
        cin >> s >> e >> t;
        map[s].push_back(make_pair(e, t));
    }
    //x에서 각자 집으로 돌아가기
    dijsktra(x);

    int dc[MAX];
    for(int i = 1;i<=n;i++){
        dc[i] = d[i];
    }

    for(int i = 1;i<=n;i++){
        //x에서 도달하는데 걸리는 시간 + x에서 집으로 돌아가는데 걸리는 시간 max
        result = max(result, dc[i] + dijsktra(i));
    }
    cout << result << "\n";
    return 0;
}