#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> m;
    for(int i = 0;i<skill.length();i++){
        m.insert({skill[i], i});
    }
    for(int i = 0;i<skill_trees.size();i++){
        bool able = true;
        int cnt = 0;
        for(int j = 0;j<skill_trees[i].length();j++){
            if(m.find(skill_trees[i][j])!=m.end()){
                if(m[skill_trees[i][j]]!=cnt){
                    able = false;
                    break;
                }else {
                    cnt++;
                }
            }

        }
        if(able){
                answer++;
        }
    }
    
    
    return answer;
}