#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, K, S, Y, X, cnt = 0;
int map[201][201];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
struct Virus{
    int virus;
    int y;
    int x;
};
bool cmp(const Virus& v1, const Virus& v2){
    return v1.virus < v2.virus;
}
vector<Virus> v;
void bfs(){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(map[i][j] > 0){
               v.push_back({map[i][j], i, j});
            }
        }
    }
    //바이러스 숫자가 낮은 순서대로 정렬
    sort(v.begin(), v.end(), cmp);
    while(cnt<S){
        int len = v.size();     
        for(int j = 0;j<len;j++){
            int curY = v[j].y;
            int curX = v[j].x;
            for(int dir = 0;dir<4;dir++){
                int ny = curY + dy[dir];
                int nx = curX + dx[dir];
                //범위 체크
                if(ny<0||nx<0||ny>=N||nx>=N) continue;
                if(!map[ny][nx]){
                    map[ny][nx] = v[j].virus;
                    v.push_back({map[ny][nx], ny, nx});
                }
            }
                
        }
        if(map[Y-1][X-1]>0) break;
        cnt++;
    }
    
    
}
int main(){
    
    cin >> N >> K;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin >> map[i][j];
        }
    }
    //s초후, (y, x)에 존재하는 것
    cin >> S >> Y >> X;
    bfs();
    cout << map[Y-1][X-1];
    return 0;
}