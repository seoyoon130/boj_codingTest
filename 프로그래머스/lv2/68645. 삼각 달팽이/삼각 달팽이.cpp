#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int snail[n][n];
    int value = 1, way = 0, y = 0, x = 0;
    for(int i = 0;i<n;i++){
        switch(way){
            case 0:
                for(int j = i;j<n;j++){
                    snail[y++][x] = value++;
                }
                y--;
                x++;
                way = 1;
                break;
            case 1:
                for(int j = i;j<n;j++){
                    snail[y][x++] = value++;
                }
                y--;
                x-=2;
                way = 2;
                break;
            case 2:
                for(int j = i;j<n;j++){
                    snail[y--][x--] = value++;
                }
                y+=2;
                x++;
                way = 0;
                break;
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i+1;j++){
            answer.push_back(snail[i][j]);
        }
    }
    return answer;
}