#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    for(int step = 1;step<s.size()/2+1;step++){
        string comp = "";
        //step 만큼 추출
        string prev = s.substr(0, step);
        int cnt = 1;
        for(int j = step;j<s.size();j+=step){
            if(prev == s.substr(j, step)) cnt++;
            else{
                if(cnt>=2){
                    comp += to_string(cnt)+prev;
                }
                else{
                    comp += prev;
                }
                //다시 상태 초기화 후 
                prev = s.substr(j, step);
                cnt = 1;
            }
        }
        if(cnt>=2){
            comp += to_string(cnt)+prev;
        }
        else{
            comp += prev;
        }
        answer = min(answer, (int)comp.size());
    }
    return answer;
}