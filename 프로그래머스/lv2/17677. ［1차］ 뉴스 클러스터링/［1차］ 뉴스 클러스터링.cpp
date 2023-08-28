#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    //대문자 변환
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    //2. str1, str2 다중집합 만들기
    vector<string>s1;
    vector<string>s2;
    for(int i = 0;i<str1.size();i++){
        if(str1[i]<65||str1[i]>90||str1[i+1]<65||str1[i+1]>90) continue;
        string temp = "";
        temp += str1[i];
        temp += str1[i+1];
        s1.push_back(temp);
    }
    for(int i = 0;i<str2.size();i++){
        if(str2[i]<65||str2[i]>90||str2[i+1]<65||str2[i+1]>90) continue;
        string temp = "";
        temp += str2[i]; 
        temp += str2[i+1];
        s2.push_back(temp);
    }
    //3. 비교해주려면 같은 문자가 있어야 하니까 -> 정렬
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    //4. 전체 크기 설정(합집합 구하기 위해서->합집합 = 전체 집합-교집합)
    int sumS = s1.size()+s2.size();
    int interS = 0;
    
    for(int i = 0;i<s1.size();i++){
        auto it = find(s2.begin(), s2.end(), s1[i]);
        //**find찾지 못했을때 end 반환 그렇기 때문에 end 써주는것. 
        if(it!=s2.end()){
            interS++;
            s2.erase(it);
        }
    }
    sumS -= interS;
    
    //5. 자카드 계산하기
    if(sumS == 0){
        answer = 1*65536;
    }
    else {
        double result = ((double)interS / (double)sumS) * 65536;
        answer = (int)result;
    }
    return answer;
}