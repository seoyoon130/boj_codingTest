#include <string>
#include <vector>

using namespace std;
string target = "";
string aeiou = "AEIOU";
int answer = 0;
int cnt =-1;
void dfs(string str){
    cnt++;
    if(str == target){
        answer = cnt;
        return;
    }
    if(str.length()>=5) return;
    for(int i = 0;i<5;i++){
        dfs(str+aeiou[i]);
    }
}
int solution(string word) {
   
    target = word;
    dfs("");
    return answer;
}