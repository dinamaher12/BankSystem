#ifndef BANKSYSTEM_BANKACCOUNT_H
#define BANKSYSTEM_BANKACCOUNT_H
#include<iostream>
#include<string>
#include"client.h"
using namespace std;

class client;

class bankAccount{
protected:
    string accountID;
    double balance;
    client *myclient = nullptr;
    bool is_valid = true;
public:
    bankAccount(){
        balance = 0;
    }
    bankAccount(double b){
        if(b < 0){
            is_valid = false;
        }
        else {
            balance = b;
        }
    }
    string get_ID(){
        return accountID;
    }
    double get_Balance(){
        return balance;
    }
    bool get_valid(){
        return is_valid;
    }
    void setClient(client &cl){
        myclient = &cl;
    }
    void set_ID(long long ID){ // 1 -> 001
        string temp = to_string(ID);
        while(temp.size() < 3){
            temp = '0' + temp;
        }
        accountID = "FCAI" + temp;
    }

    void set_Balance(double b){
        if(b < 0){
            is_valid = false;
        }
    }
    virtual int withdraw(double amount);
    virtual int deposit(double amount);
    bool is_saving(){
        return false;
    }
};
#endif //BANKSYSTEM_BANKACCOUNT_H
