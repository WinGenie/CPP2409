#include <iostream>
using namespace std;

int main(){
    int vowel = 0;
    int consonant = 0;
    char ch;
    while (true) {
        cout << "영문자를 입력하세요: ";
        cin >> ch;

        if (!(ch >= 'a' && ch <= 'z')) {
            cout << "유효하지 않은 입력입니다. 소문자 알파벳을 입력하세요.\n";
            continue;
        }

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowel++;
        } else {
            consonant++;
        }

        cout << "모음의 수: " << vowel << "\n";
        cout << "자음의 수: " << consonant << "\n";
    }

    return 0;
}