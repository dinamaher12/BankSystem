#ifndef BANKSYSTEM_SAVINGBANKACCOUNT_H
#define BANKSYSTEM_SAVINGBANKACCOUNT_H
#include"bankAccount.h"
class savingBankAccount : public bankAccount{
private:
    double minBalance = 1000;
public:
    savingBankAccount(){
        bankAccount(1000);
    }
    savingBankAccount(double b, double minB) : bankAccount(b){
        if(b >= minB){
            minBalance = minB;
        }
        else{
            cout << "Error, Balance should be greater than or equal min balance.\n";
            is_valid = false;
        }
    }
    double get_minBalance(){
        return minBalance;
    }
    void set_Balance(double b){
        if(b >= minBalance ){
            balance = b;
        } else
        {
            cout << "Error, Balance should be greater than or equal to MinBalance.\n";
            is_valid = false;
        }
    }
    void set_minBalance(double minB){
        minBalance = minB;
    }
    int withdraw(double amount);
    int deposit(double amount);
    bool is_saving(){
        return true;
    }
}
;
#endif //BANKSYSTEM_SAVINGBANKACCOUNT_H
