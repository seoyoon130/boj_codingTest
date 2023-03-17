#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    
    for(int i = 1;i<=s.size()/2;i++){
        int cnt = 1;
        string a = s.substr(0, i);
        //일시 저장값
        string temp = "";
        for(int j = i;j<s.size();j+=i){
            //같으면 cnt ++
            if(a==s.substr(j, i)) cnt++;
            //다르면 압축이 불가하기 때문에
            //cnt를 문자열로 바꿔 일시 저장
            else{
                if(cnt>1) temp += to_string(cnt);
                temp += a;
                a = s.substr(j, i);
                cnt = 1;
            }
        }
        if(cnt>1) temp += to_string(cnt);
        temp+=a;
        if(answer>temp.size()) answer = temp.size();
    }
    
    return answer;
}