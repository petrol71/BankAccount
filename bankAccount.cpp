#include "bankAccount.h"


AccountId::~AccountId() { }

AccountId::AccountId() { }

AccountId::AccountId(std::string id)
    : id(id) {
      // current date/time based on current system
      time_t now = time(0);
      // convert now to string form
      dateCreated = ctime(&now);
      }

char* AccountId::getDateCreated() { return dateCreated; }

std::string AccountId::getId() { return id; }

BankAccount::~BankAccount() { }

BankAccount::BankAccount() { }

BankAccount::BankAccount(AccountId* accountId)
    : accountId(accountId),
      balance(0.0) { }

void BankAccount::deposit(double amount) {
    balance += amount;
}

void BankAccount::withdraw(double amount) {
    if (amount <= balance) {
      balance -= amount;
    } else {
      std::cout << "\nAmount exceeds the current balance!" << std::endl;
    }
}

BasicAccount::~BasicAccount() { }

BasicAccount::BasicAccount() { }

BasicAccount::BasicAccount(AccountId* accountId, std::string accountType)
    : accountType("Basic account"),
      BankAccount(accountId) { }

void BasicAccount::display() {
    std::cout << "\n-------------\n";
    std::cout << "Account data" << std::endl;
    std::cout << "-------------\n";
    std::cout << "Account type: " << accountType << std::endl;
    std::cout << "Account number: " << accountId->getId() << std::endl;
    std::cout << "Account created: " << accountId->getDateCreated() << std::endl;

    std::cout << "\nBalance: " << balance << std::endl;
}

CustomerAccount::~CustomerAccount() { }

CustomerAccount::CustomerAccount() { }

CustomerAccount::CustomerAccount(AccountId* accountId, std::string accountType,
                                 std::string firstName, std::string lastName)
    : accountType("Customer account"),
      firstName(firstName),
      lastName(lastName),
      BankAccount(accountId) { }

void CustomerAccount::display() {
    std::cout << "\n-------------\n";
    std::cout << "Account data" << std::endl;
    std::cout << "-------------\n";
    std::cout << "Account type: " << accountType << std::endl;
    std::cout << "Account number: " << accountId->getId() << std::endl;
    std::cout << "Account created: " << accountId->getDateCreated() << std::endl;
    std::cout << "Account owner: "
              << firstName << ' ' << lastName << std::endl;
    std::cout << "\nBalance: " << balance << std::endl;
}

EnterpriseAccount::~EnterpriseAccount() { }

EnterpriseAccount::EnterpriseAccount() { }

EnterpriseAccount::EnterpriseAccount(AccountId* accountId, std::string accountType,
                                     std::string yTunnus, std::string companyName)
    : accountType(accountType),
      yTunnus(yTunnus),
      companyName(companyName),
      BankAccount(accountId) { }

void EnterpriseAccount::display() {
    std::cout << "\n-------------\n";
    std::cout << "Account data" << std::endl;
    std::cout << "-------------\n";
    std::cout << "Account type: " << accountType << std::endl;
    std::cout << "Account number: " << accountId->getId() << std::endl;
    std::cout << "Account created: " << accountId->getDateCreated() << std::endl;
    std::cout << "Account owner: "
              << companyName << std::endl;
    std::cout << "Company id: " << yTunnus << std::endl;              
    std::cout << "\nBalance: " << balance << std::endl;
}