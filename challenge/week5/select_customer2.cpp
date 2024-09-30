#include <iostream>
#include <string>
using namespace std;

int main(){
    const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];
    int userinput;
    int max;
    int min;

    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;

    for (int i = 0; i < maxPeople; i++){
        cout << "사람 " << i+1 << "의 이름: ";
        cin >> names[i];
        cout << "사람 " << i+1 << "의 나이: ";
        cin >> ages[i];
    }
    cout << endl;
    


    cout << "선택해주세요: (1)가장 나이가 많은 사람 출력 (2) 가장 나이가 적은 사람 출력 (3) 종료" << endl;
    cin >> userinput;
      
    
    switch (userinput)
    {
    case 1:
        max = ages[0];
        for (auto elem : ages){
        if (elem > max)
            max = elem;
    }
    cout << "최대값=" << max << "이름은" << names[max] << endl;
        break;
    case 2:
        min = ages[0];
        for (auto elem : ages){
            if (elem < min)
            {
            min = elem;           
            }
    cout << "최소값=" << min << "이름은" << names[min] << endl;           
        }
    case 3:
        cout << "종료합니다";
        break;
    default:
        cout << "다른 메뉴를 선택해주세요";
    }
    }
    