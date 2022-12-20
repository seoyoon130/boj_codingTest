#include <iostream>
#include<algorithm>
#include <queue>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
//우선순위 큐
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int num;
        cin >> num;
        if (num == 0) {
            if (pq.empty()) cout << 0 << "\n";
            else {
                cout << pq.top().second << "\n";
                pq.pop();
            }

        
        }
        else {
            pq.push({ abs(num), num });
        }
    }
}