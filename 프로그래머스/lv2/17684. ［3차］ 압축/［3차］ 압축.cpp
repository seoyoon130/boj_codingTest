#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dictionary;
    int num = 1;
    for(char ch = 'A'; ch<='Z';ch++){
        //char를 string 으로 바꿔주기
        string s(1, ch);
        dictionary[s] = num++;
    }
    string w;
    for(char c : msg){
        string wc = w+c;
        //기존 사전에 문자열이 존재한다면
        if(dictionary.find(wc)!=dictionary.end()){
            w = wc;
        }else{
            answer.push_back(dictionary[w]);
            dictionary[wc] = num++;
            w = string(1, c);
        }
    }
    if(!w.empty()){
        answer.push_back(dictionary[w]);
    }
    return answer;
}