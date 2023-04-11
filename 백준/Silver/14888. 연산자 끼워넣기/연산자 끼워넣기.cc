#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
int MAX= -21e8;
int MIN = 21e8;
int num[11];
int oper[4];
void dfs(int plus, int minus, int multiple, int divide, int x, int sum){
    if(x==n-1){
        if(sum<MIN) MIN = sum;
        if(sum>MAX)MAX = sum;
    }
        if(plus>0) dfs(plus-1, minus, multiple, divide, x+1, sum+num[x+1]);
        if(minus>0) dfs(plus, minus-1, multiple, divide, x+1, sum-num[x+1]);
        if(multiple>0) dfs(plus, minus, multiple-1, divide, x+1, sum*num[x+1]);
        if(divide>0) dfs(plus, minus, multiple, divide-1, x+1, sum/num[x+1]);

    
}
int main(){
    
     cin >> n;
    for(int i = 0;i<n;i++){
        cin >> num[i];
    }
    for(int i = 0;i<4;i++){
        cin >> oper[i];
    }
    dfs(oper[0], oper[1], oper[2], oper[3], 0, num[0]);
    cout <<MAX << "\n" << MIN;
    return 0;
}