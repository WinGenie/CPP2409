#include <iostream>
using namespace std;

int main(){
    int floor;
    cout << "몇 층을 쌓으시겠습니까? (1~100): ";
    cin >> floor;

    for (int i = 1; i <= floor; i++){
        for (int j = 1; j <= floor-i; j++){
            cout << "S";
        }
        for (int k = 1; k <= i*2-1; k++){
        cout << "*";
    }
    cout << endl;
    }
    return 0;
}
    