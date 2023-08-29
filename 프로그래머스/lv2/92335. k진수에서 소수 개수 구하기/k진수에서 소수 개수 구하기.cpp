#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
bool checkPrime(long long n){
    if(n==0||n==1){
        return false;
    }
    for(int i = 2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    string num;
    //1. k진수로 바꾸기
    while(n>0){
        num+=to_string(n%k);
        n = n/k;
    }
    reverse(num.begin(), num.end());
    
    //2. 0만나면 저장해주기
    string temp = "";
    for(auto c : num){
        if(c=='0'){
            if(temp.length()==0) continue;
            if(checkPrime(stol(temp))==true){
                answer++;
            }
            temp = "";
        }else{
            temp+=c;
        }
    }
    if(temp.length()!=0){
        if(checkPrime(stol(temp))==true) answer++;
    }
    
    return answer;
}