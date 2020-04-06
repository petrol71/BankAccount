#include "bankAccount.h"

//Test drive for bankAccount
int main() {

    std::string accountId("FI4950009420028730");
    AccountId id(accountId);
    BasicAccount basic(&id, "basic");
    basic.display();
    basic.deposit(1000);
    basic.display();
    basic.withdraw(500);
    basic.display();

    std::string accountId2("FI4950009420028731");
    AccountId id2(accountId2);
    CustomerAccount customer(&id2, "customer", "Olli", "Ostaja");
    customer.display();
    customer.deposit(5000);
    customer.display();
    customer.withdraw(1500);
    customer.display();

    std::string accountId3("FI4950009420028732");
    AccountId id3(accountId3);
    EnterpriseAccount enterprise(&id3, "enterprise", "1234567-8",
                                 "Bisnis Oy");
    enterprise.display();
    enterprise.deposit(10000);
    enterprise.display();
    enterprise.withdraw(3000);
    enterprise.display();
    enterprise.withdraw(20000);
    enterprise.display();
}