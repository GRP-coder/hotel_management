#ifndef CUSTOMER_MANAGER_H
#define CUSTOMER_MANAGER_H

#include "DatabaseConnection.h"
#include <string>

class Customer {
public:
    int id;
    std::string name;
    std::string phone;
    std::string email;
};

class CustomerManager {
public:
    CustomerManager(DatabaseConnection* dbConn);
    void addCustomer(const Customer& customer);
    Customer getCustomerById(int customerId);
    void updateCustomer(const Customer& customer);
    void deleteCustomer(int customerId);

private:
    DatabaseConnection* dbConn;
};

#endif
