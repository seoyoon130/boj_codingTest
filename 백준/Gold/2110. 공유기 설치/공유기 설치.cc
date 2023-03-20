#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int findGap(vector<int> v, int n, int c){
    int answer;
    //한개 띄어져있는 경우가 minGap임
    int minGap = 1;
    //마지막집-첫째집이 maxGap
    int maxGap = v[v.size()-1]-v[0];
    int mid;
    while(minGap<=maxGap){
        mid = (minGap + maxGap) / 2;
        int router = 1;
        int last = 0, next = 1;
        while(next<n&&router<c){
            //현재집 + mid의 위치보다 크거나 같은 곳에 있는 
            //첫번째 집에 두번째 공유기 설치
            if(v[next]>=v[last]+mid){
                router++;
                last = next;
                next = last+1;
            }else{
                next++;
            }
        }
        if(router<c){
            maxGap = mid-1;
        }
        else if(router == c){
            answer = mid;
            minGap = mid+1;

        }else{
            minGap = mid+1;
        }
    }
    return answer;
}
int main(){
    int n, c;
    vector<int> v;
    cin >> n >> c;
    for(int i = 0;i<n;i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int answer = findGap(v, n, c);
    cout << answer << "\n";
    return 0;

}