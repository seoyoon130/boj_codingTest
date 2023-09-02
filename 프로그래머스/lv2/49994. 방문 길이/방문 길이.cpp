#include <string>
#include <map>
#include <iostream>
using namespace std;


int solution(string dirs) {
    map<pair<pair<int, int>, pair<int, int>>, bool> visitedEdge;
    int answer = 0;
    int curY = 5;
    int curX = 5;
    for(int i = 0;i<dirs.size();++i){
        int startX = curX;
        int startY = curY;

        if (dirs[i] == 'U') {
            if (curX - 1 < 0)
                continue;
            curX--;
        }
        if (dirs[i] == 'D') {
            if (curX + 1 > 10)
                continue;
            curX++;
        }
        if (dirs[i] == 'L') {
            if (curY - 1 < 0)
                continue;
            curY--;
        }
        if (dirs[i] == 'R') {
            if (curY + 1 > 10)
                continue;
            curY++;
        }

        if (visitedEdge[make_pair(make_pair(startX, startY), make_pair(curX, curY))] == true)
            continue;

        visitedEdge[make_pair(make_pair(startX, startY), make_pair(curX, curY))] = true;
        visitedEdge[make_pair(make_pair(curX, curY), make_pair(startX, startY))] = true;
        answer++;
    
    
    }
    return answer;
}