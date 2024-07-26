#include"BankApplication.h"
#include<iostream>
using namespace std;

string BankApplication::getinput() {
    string input;
    cin>> input;
    if(input == "1" || input == "2" || input == "3" || input == "4"){
        return input;
    }
    else{
        return "None";
    }
}
bool BankApplication::showScreen() {
    cout << "Welcome to Fcai Bank System.\n"
         << "1-Create New Account.\n"
            "2-List all clients.\n"
            "3-Withdraw amount\n"
            "4-Deposit amount.\n";
    string choice = getinput();
    if (choice == "None") {
        cout << "Invalid input\n";
    } else if (choice == "1") {
        createAccount();

    } else if (choice == "2") {
        listAll();
    } else if (choice == "3") {
        withdraw();
    } else if (choice == "4") {
        deposit();
    } else {
        return false;
    }
    return true;
}

void BankApplication::runapp() {
    while(showScreen());
}

long long BankApplication::idtoint(string ID) {
    string n; n.substr(5,ID.size()-5);
    for(int i=0; i<n.size(); i++){
       if(!isdigit(n[i])){
           return -1;
       }
    }
    return stoll(n);
}
bool BankApplication::createAccount() {
    string name, address, phone;
    cout<<"Enter client name: \n"; getline(cin,name);
    cout<< "Enter client address: \n"; getline(cin,address);
    cout << "Enter client phone: \n"; getline(cin,phone);
    client client(name,address,phone);
    clients.push_back(client);
    cout << "choose type of account (1) Basic (2) Saving: \n"; string choice; cin >> choice;
    if(choice == "1"){
        double balance; cout << "Enter balance: \n"; cin >> balance;
        bankAccount acc = bankAccount(balance);
        if(!acc.get_valid()){
            cout << "Error, Balance is less than expected.\n";
            return false;
        }
        map[id] = &clients.back(); //1
        acc.setClient(clients.back());
        basic_accounts.push_back(acc);
        clients.back().setAcc(&basic_accounts.back());
        basic_accounts.back().set_ID(id);
        id++;
        return true;
    }
    else if(choice == "2"){
        cout << "Enter min balance: \n"; double minB; cin >> minB;
        cout << "Enter balance: \n"; double balance; cin >> balance;
        savingBankAccount acc = savingBankAccount(balance, minB);
        if(!acc.get_valid()){
            cout << "Error, Balance is less than expected.\n";
            return false;
        }
        map[id] = &clients.back();
        acc.setClient(clients.back());
        saving_accounts.push_back(acc);
        clients.back().setAcc(&saving_accounts.back());
        saving_accounts.back().set_ID(id);
        id++;
        return true;
    }
    else{
        return false;
    }
}

void BankApplication::listAll() {
    for(auto cl: clients){
        cout << "Client name: " << cl.get_name() <<endl;
        cout << "Client address: " << cl.get_address() << endl;
        cout << "Client phone: " << cl.get_phone() << endl;
        cout << "Account ID: " << cl.getAcc()->get_ID() << endl;
        if(cl.getAcc()->is_saving()){
            cout << "Account Type: Saving" << endl;
        }
        else{
            cout << "Account Type: Basic" << endl;
        }
        cout << "Balance: " << cl.getAcc()->get_Balance()<< endl;
    }

}
bool BankApplication::withdraw() {
    cout << "Enter Account ID: "; string ID; cin >> ID;
    long long num = idtoint(ID);
    if(num == -1){
        cout << "Withdraw Failed" << endl;
        return -1;
    }
    bankAccount *acc = map[num]->getAcc();
    cout << "Account ID: " << ID << endl;
    if(acc->is_saving()){
        cout << "Account Type: Saving.\n";
    }
    else{
        cout << "Account Type: Basic.\n";
    }
    cout << "Balance: " << acc->get_Balance() << endl;
    cout << "Enter the amount you want to withdraw: "; double amt; cin >> amt;
    return acc->withdraw(amt);

}
bool BankApplication::deposit() {
    cout << "Enter Account ID: "; string ID; cin >> ID;
    long long num = idtoint(ID);
    if(num == -1){
        cout << "Deposit Failed" << endl;
        return -1;
    }
    bankAccount *acc = map[num]->getAcc();
    cout << "Account ID: " << ID << endl;
    if(acc->is_saving()){
        cout << "Account Type: Saving.\n";
    }
    else{
        cout << "Account Type: Basic.\n";
    }
    cout << "Balance: " << acc->get_Balance() << endl;
    cout << "Enter the amount you want to deposit: "; double amt; cin >> amt;
    return acc->deposit(amt);


}