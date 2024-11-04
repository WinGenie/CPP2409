#include <iostream>
#include <string>
using namespace std;

class BankAccount{
    private:
        double balance;
        string accountHolderName;
    public:
        BankAccount(string name, double initialBalance){
            accountHolderName = name;
            balance = initialBalance;
        }
        double getBalance() const{
            return balance;
        }
        void deposit(double amount){
            if(amount > 0){
                balance += amount;
                cout << amount << " deposited. Current balance: " << balance << endl;
            }
        }
        void withdraw(double amount){
            if (amount > 0 && amount <= balance){
                balance -= amount;
                cout << amount << " withdrawn. Current balance: " << balance << endl;
            }
            else{
                cout << "Insufficient balance or invaild amount!" << endl;
            }
        }
};

int main(){
    BankAccount myAccount("Alice", 100);

    cout << "Initial Balacne : " << myAccount.getBalance() << endl;

    myAccount.deposit(500);
    myAccount.withdraw(200);

    //myAccount.blance = 5000; 에러
    //myAccount.accountHolderName = "Bob"; 에러

    return 0;
}