#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    int num;
    cin >> n;
    vector<int> v, w;
    for(int i = 0;i<n;i++){
        cin >> num;
        v.push_back(num);
        w.push_back(num);
    }
    sort(v.begin(), v.end());
    //중복 제거
    v.erase(unique(v.begin(), v.end()),v.end());
    for(auto a : w){
        cout << lower_bound(v.begin(), v.end(), a)-v.begin() <<" ";
    }

    return 0;
}