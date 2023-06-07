#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int n = elements.size();
    unordered_set<int> sums; // 부분 수열의 합을 저장하기 위한 set

    // 모든 가능한 연속 부분 수열을 생성하여 합을 계산
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < i + n; j++) {
            sum += elements[j % n]; // 원형 수열에서 인덱스 계산을 위해 j % n 사용
            sums.insert(sum);
        }
    }

    return sums.size();
}
