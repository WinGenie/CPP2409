#include "user.h"

User::User() : hp(20) {}

void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
    if (hp < 0) hp = 0; // HP는 음수로 내려가지 않음
}

void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

int User::GetHP() const {
    return hp;
}
