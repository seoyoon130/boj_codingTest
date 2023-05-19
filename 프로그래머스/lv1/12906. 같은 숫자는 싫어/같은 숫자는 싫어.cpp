#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> v;
    for(int i = 0;i<arr.size();i++){
        if(v.size()==0 || v[v.size()-1]!=arr[i]){
            v.push_back(arr[i]);
        }
    }

    return v;
}