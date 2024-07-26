#include"bankAccount.h"
int bankAccount::withdraw(double amount){
    if(amount > balance){
        cout << "Error, This is more than what you can withdraw.\n";
        return 0;
    }
    else{
        balance -= amount;
        cout << "New Balance: " << balance << "\n";
        return 1;
    }
}
int bankAccount::deposit(double amount){
    if(amount < 0){
        cout << "Error, This is less than what you can deposit.\n";
        return 0;
    }
    else{
        balance += amount;
        cout << "New Balance: " << balance << "\n";
        return 1;
    }
}
