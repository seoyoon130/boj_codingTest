#include <string>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

bool isCheck(string s) {
    stack<char> stk;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
            stk.push(s[i]);
        } else {
            if (stk.empty()) {
                return false;
            }
            if (s[i] == ']' && stk.top() != '[') {
                return false;
            }
            if (s[i] == '}' && stk.top() != '{') {
                return false;
            }
            if (s[i] == ')' && stk.top() != '(') {
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}

int solution(string s) {
    int answer = 0;
    deque<char> dq;
    int cnt = s.size();
    for (int i = 0; i < s.size(); i++) {
        dq.push_back(s[i]);
    }
    for (int i = 0; i < cnt; i++) {
        if (isCheck(string(dq.begin(), dq.end()))) {
            answer++;
        }
        dq.push_back(dq.front());
        dq.pop_front();
    }
    return answer;
}
