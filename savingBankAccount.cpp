#include"savingBankAccount.h"
int savingBankAccount::withdraw(double amount){
    if((balance-amount) >= minBalance){
        return bankAccount::withdraw(amount);
    } else{
        cout << "Error, This is more than what you can withdraw.\n";
        return 0;
    }
}
int savingBankAccount::deposit(double amount){
    if(amount >= 100){
        return bankAccount::deposit(amount);
    } else{
        cout << "Error, This is less than what you can deposit.\n";
        return 0;
    }

}

