#include <iostream>
using namespace std;

int main(){
    int a,b,c,largest;

    cout << "3개의 정수를 입력하시오: ";
    cin >> a >> b >> c;

    if (a >= b && a >= c) // a가 b,c와 각각 크거나 같은 경우에도 최대값은 a
        largest = a;
    else if (b >= a && b >= c) // b가 a,c와 각각 크거나 같은 경우에도 최대값은 b
        largest = b;
    else 
        largest = c;
    
    cout << "가장 큰 정수는" << largest << endl;
    return 0;
}