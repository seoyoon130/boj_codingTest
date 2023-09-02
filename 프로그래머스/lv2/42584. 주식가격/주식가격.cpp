#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0); // 결과 벡터를 0으로 초기화
    stack<int> stk;

    for (int i = 0; i < prices.size(); i++) {
        // 주식 가격이 떨어졌을 때
        while (!stk.empty() && prices[stk.top()] > prices[i]) {
            int top = stk.top();
            stk.pop();
            answer[top] = i - top;
        }
        stk.push(i);
    }

    // 스택에 남은 주식 가격은 가격이 떨어지지 않은 것들이므로
    // 끝까지 유지된 시간을 계산합니다.
    while (!stk.empty()) {
        int top = stk.top();
        stk.pop();
        answer[top] = prices.size() - 1 - top;
    }

    return answer;
}