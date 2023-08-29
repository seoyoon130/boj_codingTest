#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> heap(scoville.begin(), scoville.end());

    //최소힙을 구성하면, 매번 정렬과 k값 찾기를 안해도 됨!

    while(heap.size()>=2&&heap.top()<K){
        int first = heap.top();
        heap.pop();
        int second = heap.top();
        heap.pop();
        
        int newS = first + (second*2);
        
        heap.push(newS);
        answer++;
    }
    if(heap.top()<K){
        return -1;
    }
    return answer;
}