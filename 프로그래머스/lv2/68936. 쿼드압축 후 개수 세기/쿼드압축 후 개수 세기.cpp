#include <string>
#include <vector>

using namespace std;
vector<vector<int>> map;
void dfs(int y, int x, int k, vector<int> &answer){
    bool zero, one;
    zero = one = true;
    for(int i = y;i<y+k;i++){
        for(int j = x;j<x+k;j++){
            if(map[i][j] == 0) one = false;
            if(map[i][j] == 1) zero = false;
        }
    }
    if(zero == true){
        answer[0]++;
        return;
    }
    if(one == true){
        answer[1]++;
        return;
    }
    dfs(y, x, k/2, answer);
    dfs(y, x+k/2, k/2, answer);
    dfs(y+k/2, x, k/2, answer);
    dfs(y+k/2, x+k/2, k/2, answer);
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    int n = arr.size();
    //1. arr copy
    map = arr;
    //2. 재귀
    dfs(0, 0, n, answer);
    
    return answer;
}