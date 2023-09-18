#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool keep = true;

    while (keep) {
        bool block[30][30] = {false,};
        keep = false;

        // 블록 지우기
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (board[i][j] == ' ') continue;
                char target = board[i][j];
                if (target == board[i+1][j] && target == board[i+1][j+1] && target == board[i][j+1]) {
                    block[i][j] = true;
                    block[i+1][j] = true;
                    block[i+1][j+1] = true;
                    block[i][j+1] = true;
                    keep = true;
                }
            }
        }

        // 블록 지우기에 따른 블록 표시
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (block[i][j]) {
                    answer++;
                    board[i][j] = ' ';
                }
            }
        }

        // 블록 내리기
        for (int j = 0; j < n; j++) {
            for (int i = m - 1; i >= 0; i--) {
                if (board[i][j] == ' ') {
                    for (int k = i - 1; k >= 0; k--) {
                        if (board[k][j] != ' ') {
                            board[i][j] = board[k][j];
                            board[k][j] = ' ';
                            break;
                        }
                    }
                }
            }
        }
    }

    return answer;
}
