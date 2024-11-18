#define USER_H
#include <iostream>
using namespace std;
class User {
private:
    int hp;
    int itemCnt;

public:
    User();
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    int GetHP() const;
    void IncreaseItemCount();
    int GetItemCount() const;
    
    friend ostream& operator<<(ostream& os, const User& user);
};

