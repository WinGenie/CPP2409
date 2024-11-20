#include <iostream>
#include <vector>
#include <string>
#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;

bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(const vector<vector<int>>& map, int mag_x, int mag_y, int war_x, int war_y);
bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y);
void checkState(const vector<vector<int>>& map, User& user, int user_x, int user_y);
void moveUser(int &user_x, int &user_y, int deltaX, int deltaY, const vector<vector<int>>& map, User& user);

int main() {
    vector<vector<int>> map = { {0, 1, 2, 0, 4},
                                {1, 0, 0, 2, 0},
                                {0, 0, 0, 0, 0},
                                {0, 2, 3, 0, 0},
                                {3, 0, 0, 0, 2} };

    Magician magician;
    Warrior warrior;
    int mag_x = 0, mag_y = 0;
    int war_x = 0, war_y = 0;
    bool isMagicianTurn = true;

    while (true) {
        string user_input;
        User* currentUser = isMagicianTurn ? static_cast<User*>(&magician) : static_cast<User*>(&warrior);
        int& user_x = isMagicianTurn ? mag_x : war_x;
        int& user_y = isMagicianTurn ? mag_y : war_y;

        cout << (isMagicianTurn ? "Magician" : "Warrior") << "의 차례입니다. ";
        cout << "HP: " << currentUser->GetHP() << " | 명령어를 입력하세요 (상, 하, 좌, 우, 지도, 정보, 공격, 종료): ";
        cin >> user_input;

        if (user_input == "상") {
            cout << "위쪽으로 이동합니다." << endl;
            moveUser(user_x, user_y, 0, -1, map, *currentUser);
        } else if (user_input == "하") {
            cout << "아래쪽으로 이동합니다." << endl;
            moveUser(user_x, user_y, 0, 1, map, *currentUser);
        } else if (user_input == "좌") {
            cout << "왼쪽으로 이동합니다." << endl;
            moveUser(user_x, user_y, -1, 0, map, *currentUser);
        } else if (user_input == "우") {
            cout << "오른쪽으로 이동합니다." << endl;
            moveUser(user_x, user_y, 1, 0, map, *currentUser);
        } else if (user_input == "지도") {
            cout << "지도를 출력합니다." << endl;
        } else if (user_input == "정보") {
            cout << *currentUser << endl;
        } else if (user_input == "공격") {
            cout << "공격합니다." << endl;
            currentUser->doAttack();
        } else if (user_input == "종료") {
            cout << "게임을 종료합니다." << endl;
            break;
        } else {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        displayMap(map, mag_x, mag_y, war_x, war_y);

        if (currentUser->GetHP() <= 0) {
            cout << (isMagicianTurn ? "Magician" : "Warrior") << "의 체력이 모두 소진되었습니다. 공략에 실패하였습니다." << endl;
            break;
        }

        if (checkGoal(map, user_x, user_y)) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            break;
        }

        isMagicianTurn = !isMagicianTurn;
    }
    return 0;
}

void moveUser(int &user_x, int &user_y, int deltaX, int deltaY, const vector<vector<int>>& map, User& user) {
    int nextX = user_x + deltaX;
    int nextY = user_y + deltaY;

    if (!checkXY(nextX, mapX, nextY, mapY)) {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
    } else {
        user_x = nextX;
        user_y = nextY;
        user.DecreaseHP(1);
        checkState(map, user, user_x, user_y);
    }
}

void displayMap(const vector<vector<int>>& map, int mag_x, int mag_y, int war_x, int war_y) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == mag_y && j == mag_x && i == war_y && j == war_x) {
                cout << " MW   |";
            } else if (i == mag_y && j == mag_x) {
                cout << " M    |";
            } else if (i == war_y && j == war_x) {
                cout << " W    |";
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

bool checkXY(int user_x, int mapX, int user_y, int mapY) {
    return (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY);
}

bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y) {
    return (map[user_y][user_x] == 4);
}

void checkState(const vector<vector<int>>& map, User& user, int user_x, int user_y) {
    switch (map[user_y][user_x]) {
        case 1:
            cout << "아이템이 있습니다." << endl;
            user.IncreaseItemCount();
            break;
        case 2:
            cout << "적을 만났습니다! 체력이 2 감소합니다." << endl;
            user.DecreaseHP(2);
            break;
        case 3:
            cout << "포션을 발견했습니다! 체력이 2 회복됩니다." << endl;
            user.IncreaseHP(2);
            break;
    }
}
