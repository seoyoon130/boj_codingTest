#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> name; // 유저 아이디와 닉네임을 저장하는 맵

    for (int i = 0; i < record.size(); i++) {
        int space1 = record[i].find(' ');
        int space2 = record[i].find(' ', space1 + 1);
        string command = record[i].substr(0, space1);
        string userId = record[i].substr(space1 + 1, space2 - space1 - 1);

        if (command == "Enter" || command == "Change") {
            string userName = record[i].substr(space2 + 1);
            name[userId] = userName; // userId와 userName 맵 업데이트
        }
    }

    for (int i = 0; i < record.size(); i++) {
        int space1 = record[i].find(' ');
        int space2 = record[i].find(' ', space1 + 1);
        string command = record[i].substr(0, space1);
        string userId = record[i].substr(space1 + 1, space2 - space1 - 1);

        if (command == "Enter") {
            answer.push_back(name[userId] + "님이 들어왔습니다.");
        } else if (command == "Leave") {
            answer.push_back(name[userId] + "님이 나갔습니다.");
        }
    }

    return answer;
}
