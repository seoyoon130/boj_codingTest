#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int dp[16];
int T[15], P[15];
int maxValue;
int solve(int day){
    if(day>n) return -98765321;
    if(day==n) return 0;
    int &ret = dp[day];
    if(ret!=-1) return ret;
    ret = max(solve(day+1), solve(day+T[day])+P[day]);
    return ret;
}
int main(){
    cin >> n;
    for(int i = 0;i<n;i++){
        int x,y;
        cin >> x >> y;
        T[i] = x;
        P[i] = y;
        dp[i] = -1;
    }
    int ret = solve(0);
    cout << ret;

    return 0;
}