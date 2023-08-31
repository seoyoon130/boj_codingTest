#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//0. 16진수까지 가능함으로 스트링 형식으로 0~F까지 선언
string numbers = "0123456789ABCDEF";
string num_to_base(int n, int base){
    string r = "";
    while(n>0){
        r+=numbers[n%base];
        n/=base;
    }
    //진법이니까 바꿔주어야함

    reverse(r.begin(), r.end());
                

    return r;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    string a = "0";
    //1. 해당 진법으로 바꿔주기
    //t*m 인 이유는 만약 2명이서 미리 구할 숫자가 4개라면 => 길이 8개인거만 구하면 되기 때문에
    for(int i = 1;a.size()<=t*m;i++){
        a+=num_to_base(i, n);
    }
    //2. 해당되는 숫자 구해주기
    for(int i = p-1;i<t*m;i+=m){
        answer += a[i];
    }
    return answer;
}