#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> word;
    word[words[0]]++;
    
    for(int i = 1;i<words.size();i++){
        //1. 뒤글자가 앞글자와 다를때
        if(words[i-1].back()!=words[i].front()) {
            cout << "같지않음";
            return {(i%n)+1, (i/n)+1};
            
        }
        //2. 이미 말한 단어라면
        else if(word[words[i]]){
            cout << "이미 말했다";
            return {(i%n)+1, (i/n)+1};

        }
        else {
            word[words[i]]++;
        }
        
    }
   
    
    return {0, 0};
}