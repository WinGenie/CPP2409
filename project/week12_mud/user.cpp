#include "user.h"
using namespace std;

User::User() : hp(20), itemCnt(0) {}

void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
    if (hp < 0) hp = 0; 
}

void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

int User::GetHP() const {
    return hp;
}

void User::IncreaseItemCount() {
    itemCnt++;
}

int User::GetItemCount() const {
    return itemCnt;
}

ostream& operator<<(ostream& os, const User& user) {
    os << "현재 HP는 " << user.GetHP() << "이고, 먹은 아이템은 총 " << user.GetItemCount() << "개 입니다";
    return os;
}
