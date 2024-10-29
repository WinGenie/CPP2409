#include <iostream>
#include <string>
#include <cstdlib> // for rand
#include <ctime>   // for time
using namespace std;

// 모든 자릿수가 다른지 확인하는 함수
bool checkNumber(int number) {
    int first = number / 100;
    int second = (number / 10) % 10;
    int third = number % 10;

    return (first != second && second != third && first != third);
}

int main() {
    srand(time(0)); // 랜덤 시드 초기화
    int randomNum;  // 맞춰야 하는 3자리 숫자
    int firstNum, secondNum, thirdNum;

    // 3자리 숫자를 만들고 자릿수가 모두 다른지 체크하는 코드
    while (true) {
        randomNum = rand() % 900 + 100; // 100부터 999 사이의 랜덤 숫자 생성

        if (checkNumber(randomNum)) { // 자릿수가 모두 다르면 while문 탈출
            firstNum = randomNum / 100;
            secondNum = (randomNum / 10) % 10;
            thirdNum = randomNum % 10;
            break;
        }
    }

    cout << "정답: " << randomNum << endl; // 테스트용 출력 (나중에 삭제 가능)

    int turn = 0;
    while (true) {
        cout << turn + 1 << "번째 시도입니다." << endl;

        int userNumber; // 사용자가 입력한 세자리 수
        int guessFirst, guessSecond, guessThird;

        // 사용자에게 세자리 수를 입력받고 자릿수가 모두 다른지 체크
        while (true) {
            cout << "세자리 수를 입력해주세요: ";
            cin >> userNumber;

            if (to_string(userNumber).length() != 3) {
                cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
                continue;
            }

            if (checkNumber(userNumber)) { // 자릿수가 모두 다르면 while문 탈출
                guessFirst = userNumber / 100;
                guessSecond = (userNumber / 10) % 10;
                guessThird = userNumber % 10;
                break;
            } else {
                cout << "각 자릿수가 모두 다른 숫자를 입력해주세요." << endl;
            }
        }

        // 스트라이크와 볼을 계산하는 코드
        int strike = 0, ball = 0;

        if (guessFirst == firstNum) strike++;
        else if (guessFirst == secondNum || guessFirst == thirdNum) ball++;

        if (guessSecond == secondNum) strike++;
        else if (guessSecond == firstNum || guessSecond == thirdNum) ball++;

        if (guessThird == thirdNum) strike++;
        else if (guessThird == firstNum || guessThird == secondNum) ball++;

        cout << userNumber << "의 결과: " << strike << " 스트라이크, " << ball << " 볼입니다." << endl;

        // 정답을 맞춘 경우 종료
        if (strike == 3) {
            cout << "정답을 맞췄습니다. 축하합니다!" << endl;
            break;
        }

        turn++;
    }

    return 0;
}
