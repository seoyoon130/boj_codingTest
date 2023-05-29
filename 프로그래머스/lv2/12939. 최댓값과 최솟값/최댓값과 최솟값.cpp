#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    string temp = "";
    vector<int> ans;
    for(int i = 0;i<s.size();i++){
        if(s[i] == ' ') {
            ans.push_back(stoi(temp));
            temp.clear();
        } else temp+=s[i];
    }
    ans.push_back(stoi(temp));
    sort(ans.begin(), ans.end());
    answer = to_string(ans.front()) + " " + to_string(ans.back());
    for(auto v : ans){
        cout << v  << " ";
    }
    cout << "\n" << temp;
    return answer;
}