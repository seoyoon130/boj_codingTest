#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b){
    return a.second<b.second;
}
int solution(vector<int> food_times, long long k) {
    int n = food_times.size();
    vector<pair<int, int>> foods;
    for(int i = 0;i<n;i++){
        foods.push_back(make_pair(food_times.at(i), i+1));
    }
    //푸드 시간 별로 정렬 (오름차순)
    sort(foods.begin(), foods.end());
    
    int pretime = 0;
    for(auto it = foods.begin(); it!=foods.end(); ++it, --n){
        //곱하기 때문에 범위를 벗어날 수 있으므로
        long long spend = (long long)(it->first - pretime) * n;
        if(spend == 0)continue;
        if(spend<=k){
            k-=spend;
            pretime = it->first;
        }else {
            k %=n;
            sort(it, foods.end(), comp);
            return (it+k)->second;
        }
        
    }
    return -1;
}