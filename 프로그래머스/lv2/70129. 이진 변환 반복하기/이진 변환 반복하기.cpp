#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string temp;
    int zeroCount = 0;
    int convertCount = 0;
    
    while(s != "1"){
        // 0 제거하기
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') {
                zeroCount++;
                continue;
            }
            else {
                temp += s[i];
            }
        }
        
        // 길이를 이진수로 변환하기
        int size = temp.size();
        s = "";
        while(size != 0){
            if(size % 2 == 1) {
                s = '1' + s;
            }
            else {
                s = '0' + s;
            }
            size /= 2;
        }
        
        temp = "";
        convertCount++;
    }
    
    answer.push_back(convertCount);
    answer.push_back(zeroCount);
   
    return answer;
}
