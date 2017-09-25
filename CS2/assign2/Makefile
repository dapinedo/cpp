#Makefile
all: BankAccountListDriver

BankAccountListDriver: BankAccountList BankAccount BankAccountListDriver.cpp
	g++ -std=c++11 -o BankAccountListDriver BankAccountList.o BankAccount.o BankAccountListDriver.cpp

BankAccountList: BankAccountList.cpp
	g++ -std=c++11 -c -o BankAccountList.o BankAccountList.cpp

BankAccount: BankAccount.cpp
	g++ -std=c++11 -c -o BankAccount.o BankAccount.cpp