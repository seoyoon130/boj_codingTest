#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
bool compareByFee(const pair<string, int>& a, const pair<string, int>& b) {
    return a.first< b.first;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<pair<string, int>> answer;
    vector<int> ans;
    int time = fees[0];
    int fee = fees[1];
    int unit_time = fees[2];
    int unit_fee = fees[3];
    //차량번호, (누적주차시간, 입차시간)
    unordered_map<string, pair<int, int>> parking_lot;
    unordered_map<string, bool> chk;
    
      for (string record : records) {
        string time = record.substr(0, 5);
        string car_number = record.substr(6, 4);
        string action = record.substr(11);
        int num = 0;
        if(action == "IN"){
            parking_lot[car_number].second = stoi(time.substr(0, 2))*60 + stoi(time.substr(3));
            chk[car_number]  = true;
        }
          else if(action == "OUT"){
              int in_time = parking_lot[car_number].second;
              int out_time = stoi(time.substr(0, 2))*60 + stoi(time.substr(3))-in_time;
              parking_lot[car_number].first += out_time;
            chk[car_number]  = false;

          }
    }
    
    
    //2. 누적 가격 구하기
    for(auto entry : parking_lot){
        string carNum = entry.first;
        int total_time = 0;
        if(chk[carNum]==true){
            //300이 나와야함
            //누적 주차시간 구하기
            total_time = ((23*60+59)-parking_lot[carNum].second)+parking_lot[carNum].first;
        }
        else{
            total_time = parking_lot[carNum].first;
        }
        int total_fee = fee;
         if (total_time > time) {
            total_fee += ceil((double)(total_time - time) / unit_time) * unit_fee;
        }
        
        answer.push_back(make_pair(carNum, total_fee));
        sort(answer.begin(), answer.end(), compareByFee);
        
        
    }
    for(auto v : answer){
            ans.push_back(v.second);
    }
   return ans;

}