#ifndef BANKSYSTEM_BANKAPPLICATION_H
#define BANKSYSTEM_BANKAPPLICATION_H
#include"client.h"
#include"bankAccount.h"
#include"savingBankAccount.h"
#include<vector>
#include<map>
class BankApplication{
private:
    vector<client>clients;
    vector<bankAccount>basic_accounts;
    vector<savingBankAccount>saving_accounts;
    long long id = 1;
    map<long long, client*> map;
public:
    long long idtoint(string ID);
    string getinput();
    bool showScreen();
    bool createAccount();
    void listAll();
    bool withdraw();
    bool deposit();
    void runapp();
};
#endif //BANKSYSTEM_BANKAPPLICATION_H
