#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    int temp = n/2;
    for(int i = 1;i<=temp;i++){
        int sum = 0;
        for(int j = i;j<=n;j++){
            sum+=j;
            if(sum==n) {
                answer++;
                break;
            }
            else if(sum>n) break;
        }
    }
    return answer;
}