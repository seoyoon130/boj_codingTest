#include <iostream>
using namespace std;
int num;
int n;
//dp문제 이므로
//우선 dp 테이블을 만들자!
//일단 기본적인 테이블을 만들어야지 편함
//0은 0, 1, 2는 1 / 3은 4가지 (1+1+1, 1+2, 2+1, 3)
int dp[12] = {0, 1, 2, 4};
void find(int num){
    //다른 숫자의 dp 테이블을 만든다.
    for(int i = 4;i<11;i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
}
int main(){
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> num;
        find(num);
        cout << dp[num] << "\n";
    }
    return 0;
}