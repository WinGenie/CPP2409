#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int &hp, int user_x, int user_y);
void moveUser(int &user_x, int &user_y, int deltaX, int deltaY, int map[][mapX], int &hp);

// 메인 함수
int main() {
    int map[mapY][mapX] = { {0, 1, 2, 0, 4},
                            {1, 0, 0, 2, 0},
                            {0, 0, 0, 0, 0},
                            {0, 2, 3, 0, 0},
                            {3, 0, 0, 0, 2} };

    int user_x = 0; // 가로 번호
    int user_y = 0; // 세로 번호
    int hp = 20; // 초기 체력

    while (true) {
        string user_input = "";
        cout << "현재 HP : " << hp << " | 명령어를 입력하세요 (상, 하, 좌, 우, 지도, 종료): ";
        cin >> user_input;

        if (user_input == "상") {
            cout << "위쪽으로 이동합니다." << endl;
            moveUser(user_x, user_y, 0, -1, map, hp);
        } else if (user_input == "하") {
            cout << "아래쪽으로 이동합니다." << endl;
            moveUser(user_x, user_y, 0, 1, map, hp);
        } else if (user_input == "좌") {
            cout << "왼쪽으로 이동합니다." << endl;
            moveUser(user_x, user_y, -1, 0, map, hp);
        } else if (user_input == "우") {
            cout << "오른쪽으로 이동합니다." << endl;
            moveUser(user_x, user_y, 1, 0, map, hp);
        } else if (user_input == "지도") {
            cout << "지도를 출력합니다." << endl;
            displayMap(map, user_x, user_y);
        } else if (user_input == "종료") {
            cout << "게임을 종료합니다." << endl;
            break;
        } else {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        if (hp <= 0) {
            cout << "체력이 모두 소진되었습니다. 공략에 실패하였습니다." << endl;
            break;
        }

        if (checkGoal(map, user_x, user_y)) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            break;
        }
    }
    return 0;
}

// 좌표와 지도 상태에 따른 행동 수행 함수
void moveUser(int &user_x, int &user_y, int deltaX, int deltaY, int map[][mapX], int &hp) {
    int nextX = user_x + deltaX;
    int nextY = user_y + deltaY;

    if (!checkXY(nextX, mapX, nextY, mapY)) {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
    } else {
        user_x = nextX;
        user_y = nextY;
        hp--; // 이동할 때마다 체력 1 감소
        checkState(map, hp, user_x, user_y);
        displayMap(map, user_x, user_y);
    }
}

// 지도와 사용자 위치 출력 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y && j == user_x) {
                cout << " USER |";
            } else {
                int posState = map[i][j];
                switch (posState) {
                    case 0: cout << "      |"; break;
                    case 1: cout << "아이템|"; break;
                    case 2: cout << "  적  |"; break;
                    case 3: cout << " 포션 |"; break;
                    case 4: cout << "목적지|"; break;
                }
            }
        }
        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}

// 지도 내 유효한 위치인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
    return (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY);
}

// 유저가 목적지에 도달했는지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y) {
    return (map[user_y][user_x] == 4);
}

// 위치 상태를 체크하고 체력 및 메시지 조정하는 함수
void checkState(int map[][mapX], int &hp, int user_x, int user_y) {
    switch (map[user_y][user_x]) {
        case 1:
            cout << "아이템이 있습니다." << endl;
            break;
        case 2:
            hp -= 2; // 적을 만나면 체력 2 감소
            cout << "적을 만났습니다! 체력이 2 감소합니다." << endl;
            break;
        case 3:
            hp += 2; // 포션을 만나면 체력 2 증가
            cout << "포션을 발견했습니다! 체력이 2 회복됩니다." << endl;
            break;
    }
}
