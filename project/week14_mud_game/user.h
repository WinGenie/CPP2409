#define USER_H
#include <iostream>
using namespace std;

class User {
private:
    int hp;
    int itemCnt;

public:
    User() : hp(20), itemCnt(0) {}
    virtual void doAttack() const = 0;
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    int GetHP() const;
    void IncreaseItemCount();
    int GetItemCount() const;
    virtual char GetType() const = 0;

    friend ostream& operator<<(ostream& os, const User& user);
};

class Magician : public User {
public:
    void doAttack() const override;
    char GetType() const override { return 'M'; }
};

class Warrior : public User {
public:
    void doAttack() const override;
    char GetType() const override { return 'W'; }
};

