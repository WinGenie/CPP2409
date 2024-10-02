#include <iostream>
#include <string>
using namespace std;

int main(){
    const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];

    int maxAgeIndices[maxPeople];
    int minAgeIndices[maxPeople];
    int maxCount = 0, minCount = 0;

    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;

    for (int i = 0; i < maxPeople; i++){
        cout << "사람 " << i+1 << "의 이름: ";
        cin >> names[i];
        cout << "사람 " << i+1 << "의 나이: ";
        cin >> ages[i];
    }
    
    int maxAge = ages[0];
    for ( int i = 1; i < maxPeople; i++){
        if (ages[i] > maxAge){
            maxAge = ages[i];
        }
    }

    int minAge = ages[0];
    for (int i = 1; i < maxPeople; i++){
        if (ages[i] < minAge){
            minAge = ages[i];
        }
    }

    for (int i = 0; i < maxPeople; i++){
        if (ages[i] == maxAge){
            maxAgeIndices[maxCount++] = i;
        }
        if (ages[i] == minAge){
            minAgeIndices[minCount++] = i;
        }
    }

    while(1){
        cout << "\n메뉴를 선택하세요:\n";
        cout << "1. 가장 나이가 많은 사람 출력\n";
        cout << "2. 가장 나이가 적은 사람 출력\n";
        cout << "3. 종료\n";
        int choice;
        cin >> choice;

        if (choice == 1){
            cout << "가장 나이가 많은 사람: ";
            for(int i = 0; i< maxCount; i++){
                cout << names[maxAgeIndices[i]] << "(" << ages[maxAgeIndices[i]] << "세)";
            }
            cout << "\n";
        }
        else if (choice == 2){
            cout << "가장 나이가 적은 사람: ";
            for (int i = 0; i < minCount; i++){
                cout << names[minAgeIndices[i]] << "(" << ages[minAgeIndices[i]] << "세)";
            }
            cout << "\n";
        }
        else if (choice == 3){
            cout << "프로그램을 종료합니다.\n";
            break;
        }
        else{
            cout << "잘못된 입력입니다. 프로그램을 종료합니다.\n";
            break;
        }
    }
    return 0;


}