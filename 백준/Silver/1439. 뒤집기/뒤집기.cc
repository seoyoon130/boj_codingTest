#include <iostream>
#include <string.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int zero = 0;
    int one = 0;
    if(s[0] == '1'){
        zero++;
    }
    else{
        one++;
    }
    for(int i = 0;i<s.size()-1;i++){
        if(s[i]!=s[i+1]){
            if(s[i+1] == '1')zero++;
            else one++;
        }
    }
    cout << min(zero, one) << "\n";
    return 0;
}