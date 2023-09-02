#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int n = land.size();
    vector<vector<int> >dp(n, vector<int>(4, 0));
    dp[0] = land[0];
    
    for(int i = 1;i<n;i++){
        for(int j = 0;j<4;j++){
            int maxVal = 0;
            for(int k = 0;k<4;k++){
                if(j!=k){
                    maxVal = max(maxVal, dp[i-1][k]);
                }
            }
            dp[i][j] = land[i][j]+maxVal;
        }
    }
    
    answer = *max_element(dp[n-1].begin(), dp[n-1].end());
    return answer;
}