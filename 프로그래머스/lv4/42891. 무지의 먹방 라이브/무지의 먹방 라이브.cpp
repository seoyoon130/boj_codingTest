#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> food_times, long long k) {
   int n = food_times.size();
    vector<pair<int, int>> foods; // 음식 시간과 인덱스를 저장하는 벡터
    for (int i = 0; i < n; ++i) {
        foods.push_back(make_pair(food_times[i], i + 1));
    }
    sort(foods.begin(), foods.end()); // 음식 시간을 기준으로 정렬

    int prev_time = 0;
    for (int i = 0; i < n; ++i) {
        long long diff = (long long)(foods[i].first - prev_time) * (n - i);
        if (diff <= k) {
            k -= diff;
            prev_time = foods[i].first;
        } else {
            vector<pair<int, int>> subfoods;
            for (int j = i; j < n; ++j) {
                subfoods.push_back(make_pair(foods[j].second, foods[j].first));
            }
            sort(subfoods.begin(), subfoods.end()); // 남은 음식을 번호 순서대로 정렬
            return subfoods[k % (n - i)].first; // 남은 음식 중에서 k번째 음식의 번호 반환
        }
    }

    return -1; // 더 이상 처리할 음식이 없는 경우
}