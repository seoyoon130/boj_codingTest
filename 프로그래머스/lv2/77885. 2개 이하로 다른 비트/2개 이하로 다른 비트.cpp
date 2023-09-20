#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i = 0;i<numbers.size();i++){
        if(numbers[i]%2==0) {
            answer.push_back(numbers[i]+1);
        }
        else{
            long long bit = 1;
            //비트가 0이면 종료
            while(true){
                if((numbers[i]&bit)==0) break;
                bit*=2;
            }
            //이전 비트를 구해서
            bit = bit/2;
            answer.push_back(numbers[i]+bit);
        }
    }
    return answer;
}