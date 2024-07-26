#ifndef BANKSYSTEM_CLIENT_H
#define BANKSYSTEM_CLIENT_H
#include<string>
#include"bankAccount.h"
using namespace std;
class client{
private:
    string name;
    string address;
    string phone;
    bankAccount *ptr;
public:
    client(string n, string a, string p){
        name = n;
        address = a;
        phone = p;
    }
    void setAcc(bankAccount *p){
        ptr = p;
    }
    string get_name(){
        return name;
    }
    string get_address(){
        return address;
    }
    string get_phone(){
        return phone;
    }
    // get account
    bankAccount* getAcc(){
        return ptr;
    }
};

#endif //BANKSYSTEM_CLIENT_H
