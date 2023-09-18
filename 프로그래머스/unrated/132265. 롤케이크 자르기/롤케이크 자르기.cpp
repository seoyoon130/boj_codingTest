#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> rightTopping;
    map<int, int> leftTopping;
    for(int i = 0;i<topping.size();i++){
        rightTopping[topping[i]]++;
    }
    for(int i = 0;i<topping.size()-1;i++){
        leftTopping[topping[i]]++;
        rightTopping[topping[i]]--;
        if(rightTopping[topping[i]]==0){
            rightTopping.erase(topping[i]);
        }
        if(rightTopping.size() == leftTopping.size()) answer++;
    }
    return answer;
}