#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,int> wantMap;

bool check(map<string,int> m)
{
    for(auto u:wantMap)
    {
        if(m.find(u.first)==m.end()) // 사려는게 할인 품목에 없다면
        {
            return false;
        }
        else if(m[u.first]!=u.second) // 사려는 수량만큼 할인 품목에 없다면
        {
            return false;
        }
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for(int i=0;i<want.size();i++)
    {
        wantMap[want[i]] = number[i];
    }
    
    for(int i=0;i<=discount.size()-10;i++)
    {
        map<string, int> m;
        for(int j=i;j<i+10;j++)
        {
            m[discount[j]]++;
        }
        answer+=check(m);
        m.clear();
    }
    return answer;
}