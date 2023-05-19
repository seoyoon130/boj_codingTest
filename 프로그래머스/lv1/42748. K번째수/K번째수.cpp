#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(int y = 0;y<commands.size();y++){
        int i, j, k;
        vector<int> copy;

        i = commands[y][0];
        j = commands[y][1];
        k = commands[y][2];
        for(int a = i-1;a<=j-1;a++){
            copy.push_back(array[a]);
            
        }
        sort(copy.begin(), copy.end());
        answer.push_back(copy[k-1]);
    
    }
    return answer;
}