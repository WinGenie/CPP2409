#include <iostream>
#include <string>
using namespace std;

string toLowerStr(string str){
    string newStr = str;
    for (char &c : newStr){
        c = tolower(c);
    }
    return newStr;
}

string toUpperStr(string str){
    string newStr = str;
    for (char& c : newStr){
        c = toupper(c);
    }
    return newStr;
}

int CalcHammingDist(string s1, string s2){
    s1 = toLowerStr(s1);
    s2 = toLowerStr(s2);
    int count = 0;
    for (int i = 0; i < s1.length(); i++){
        if(s1[i] != s2[i])
            count += 1;
    }
    return count;
}

int main(){
    string s1, s2;

    while(1){
        cout << "DNA1: ";
        cin >> s1;
        cout << "DNA2: ";
        cin >> s2;

        if (s1.length() != s2.length()){
            cout << "오류: 길이가 다름" << endl;
            continue;
        }
        else{
            int count = CalcHammingDist(s1,s2);
            cout << "해밍 거리는 " << count << endl;
            break;
        }
    }

    return 0;
}
