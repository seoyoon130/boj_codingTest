#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int n = elements.size();
    unordered_set<int> sums; // 부분 수열의 합을 저장하기 위한 set

    for (int i = 0; i < n; i++) {
        int left = i; // 왼쪽 포인터
        int right = i; // 오른쪽 포인터
        int sum = 0; // 현재 연속 부분 수열의 합

        // 투포인터를 이용하여 모든 연속 부분 수열의 합을 계산
        while (true) {
            sum += elements[right];
            sums.insert(sum);

            // 오른쪽 포인터를 한 칸 이동
            right = (right + 1) % n;

            // 원형 수열에서 더 이상 연속 부분 수열을 만들 수 없는 경우 종료
            if (right == i)
                break;
        }
    }

    return sums.size();
}
