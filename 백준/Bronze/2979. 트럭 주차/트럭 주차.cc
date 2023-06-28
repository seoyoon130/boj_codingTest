#include <iostream>
using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int time[101] = {0};
    for(int i = 0;i<3;i++){
        int start, end;
        cin >> start >> end;
        for(int j = start;j<end;j++){
            time[j]++;
        }
    }
    int sum = 0;
    for(int i = 0;i<101;i++){
        if(time[i]==1){
            sum+=time[i]*a;
        }
        else if(time[i] == 2){
            sum+=time[i]*b;
        }
        else if(time[i] == 3){
            sum+=time[i]*c;
        }
    }
    cout << sum <<endl;
    return 0;
}