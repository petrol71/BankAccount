#include <iostream>
#include <string>


class AccountId {
    std::string id;
    char* dateCreated;
public:
    ~AccountId();
    AccountId();
    AccountId(std::string id);
    std::string getId();
    char* getDateCreated();
};


class BankAccount {
protected:
    AccountId* accountId;
    double balance;
public:
    BankAccount();
    BankAccount(AccountId* accountId);
    virtual ~BankAccount();
    virtual void display() = 0;
    void deposit(double amount);
    void withdraw(double amount);
};


class BasicAccount : public BankAccount {
    std::string accountType;
public:
    ~BasicAccount();
    BasicAccount();
    BasicAccount(AccountId* accountId, std::string accountType);
    void display();
};


class CustomerAccount : public BankAccount {
    std::string accountType;
    std::string firstName;
    std::string lastName;
public:
    ~CustomerAccount();
    CustomerAccount();
    CustomerAccount(AccountId* accountId, std::string accountType,
                    std::string firstName, std::string lastName);
    void display();
};


class EnterpriseAccount : public BankAccount {
    std::string accountType;
    std::string yTunnus;
    std::string companyName;
public:
    ~EnterpriseAccount();
    EnterpriseAccount();
    EnterpriseAccount(AccountId* accountId, std::string accountType,
                      std::string yTunnus, std::string companyName);
    void display();
};