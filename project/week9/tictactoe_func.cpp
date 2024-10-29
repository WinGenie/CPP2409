#include <iostream>
using namespace std;

const int numCell = 5; // 보드판의 가로 세로 길이

// 입력 좌표의 유효성 체크 함수
bool isValid(int x, int y, char board[numCell][numCell]) {
    if (x >= numCell || y >= numCell || x < 0 || y < 0) {
        cout << "좌표가 보드를 벗어났습니다. 다시 입력하세요." << endl;
        return false;
    }
    if (board[x][y] != ' ') {
        cout << "해당 위치에 이미 돌이 놓여 있습니다. 다시 입력하세요." << endl;
        return false;
    }
    return true;
}

// 승리 체크 함수
bool checkWin(char board[numCell][numCell], char currentUser) {
    // 가로, 세로 체크
    for (int i = 0; i < numCell; i++) {
        bool rowWin = true, colWin = true;
        for (int j = 0; j < numCell; j++) {
            if (board[i][j] != currentUser) rowWin = false;
            if (board[j][i] != currentUser) colWin = false;
        }
        if (rowWin || colWin) return true;
    }

    // 대각선 체크
    bool diag1Win = true, diag2Win = true;
    for (int i = 0; i < numCell; i++) {
        if (board[i][i] != currentUser) diag1Win = false;
        if (board[i][numCell - i - 1] != currentUser) diag2Win = false;
    }

    return diag1Win || diag2Win;
}

int main() {
	int k = 0; // 누구 차례인지 체크하기 위한 변수
	char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 변수
	char board[numCell][numCell]{}; // 보드판을 나타내는 2차원 배열
	int x, y = 0; // 사용자에게 xy좌표값을 입력받기 위한 변수

	// 보드판 초기화
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// 3인용 게임으로 확장 (돌: X O H)
	char players[3] = {'X', 'O', 'H'};

	// 게임을 무한 반복
	while (true) {
		// 1. 누구 차례인지 출력
		currentUser = players[k % 3];
		cout << k % 3 + 1 << "번 유저("<< currentUser <<")의 차례입니다. -> ";

		// 2. 좌표 입력 받기
		cout << "(x, y) 좌표를 입력하세요: ";
		cin >> x >> y;

		// 3. 입력받은 좌표의 유효성 체크
		if (!isValid(x, y, board)) continue;

		// 4. 입력받은 좌표에 현재 유저의 돌 놓기
		board[x][y] = currentUser;

		// 5. 현재 보드 판 출력 (원본 코드 그대로 유지)
		for (int i = 0; i < numCell; i++) {
			for (int k = 0; k < numCell - 1; k++){
				cout << "---|";
			}
			cout << "---" << endl;
			for (int j = 0; j < numCell; j++)
			{
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << "  |";
			}
			cout << endl;
		}
		for (int k = 0; k < numCell - 1; k++){
			cout << "---|";
		}
		cout << "---" << endl;

		// 6. 승리 체크
		if (checkWin(board, currentUser)) {
			cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
			break;
		}

		// 7. 모든 칸 다 찼는지 체크하기
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "모든 칸이 다 찼습니다. 종료합니다." << endl;
			break;
		}

		k++;
	}

	return 0;
}
