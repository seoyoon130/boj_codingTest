#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;
    for(int i = 0;i<cities.size();i++){
        string city = cities[i];
        for(int j = 0;j<city.length();j++){
            city[j] = tolower(city[j]);
        }
        bool hit = false;
        int idx = 0;
        for(idx = 0;idx<cache.size();idx++){
            if(cache[idx]==city){
                hit = true;
                break;
            }
        }
        cache.push_back(city);
        if(hit){
            cache.erase(cache.begin()+idx);
            answer+=1;
        }
        else{
            if(cache.size()>cacheSize){
                cache.pop_front();
            }
            answer+=5;
        }
    }
    return answer;
}