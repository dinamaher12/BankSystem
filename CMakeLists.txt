cmake_minimum_required(VERSION 3.21)
project(BankSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(BankSystem main.cpp client.h bankAccount.cpp bankAccount.h savingBankAccount.cpp savingBankAccount.h BankApplication.cpp BankApplication.h)
