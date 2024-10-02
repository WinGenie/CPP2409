#include <iostream>
using namespace std;

int main(){
    const int numCell = 3;
    char board[numCell][numCell]{};
    int x,y;

    for(x=0; x<numCell; x++){
        for(y=0; y<numCell; y++){
            board[x][y] = ' ';
        }
    }

    int k = 0;
    char currentUser = 'X';

    while(true){
        switch(k % 2){
        case 0:
            cout << "첫 번째 유저(x)의 차례입니다 -> ";
            currentUser = 'X';
            break;
        case 1:
            cout << "두 번째 유저(O)의 차례입니다 -> ";
            currentUser = 'O';
            break;
        }
        
        cout << "(x,y) 좌표를 입력하세요(최대범위 x:2, y:2): "; //제한된 입력범위 안내
        cin >> y >> x; //x좌표부터 입력되도록 순서 변경

        if (x >= numCell || y >= numCell){
            cout << x << ", " << y << ": ";
            cout << "x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
            continue;
        }
        if (board[x][y] != ' '){
            cout << x << ", " << y << ": 이미 돌이 차 있습니다." << endl;
            continue;
        }

        board[x][y] = currentUser;

        for (int i =0; i < numCell; i++){
            cout << "---|---|---" << endl;
            for(int j=0; j < numCell; j++){
                cout << board[i][j];
                if(j == numCell - 1){
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;
        k++;
    
    
    int checked = 0;
    for (int i = 0; i < numCell; i++){
        for (int j = 0; j < numCell; j++){
            if (board[i][j] == ' '){
                checked++;
            }
        }
    }
    if (checked == 0){
        cout << "모든 칸이 다 찼습니다. 종료합니다." << endl;
    }

    bool isWin = false;
    for (int i = 0; i < numCell; i++){
        if(board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser){
            cout << "가로에 모두 돌이 놓였습니다!: ";
            isWin = true;
        }
        if(board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser){
            cout << "세로에 모두 돌이 놓였습니다!: ";
            isWin = true;
        }
    }
    
    if (board[0][0] == currentUser && board[1][1] == currentUser && board [2][2] == currentUser){
        cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!: ";
        isWin = true;
    }
    if (board[0][2] == currentUser && board[1][1] == currentUser && board [2][0] == currentUser){
        cout << "오른쪽 위에서 왼쪽쪽 아래 대각선으로 모두 돌이 놓였습니다!: ";
        isWin = true;
    }

    if (isWin == true){
        cout << k % 2 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
        cout << "종료합니다." << endl;
        break;
    }
    }
    return 0;
}