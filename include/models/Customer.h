#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
public:
    int id;
    std::string name;
    std::string phone;
    std::string email;

    Customer();
    Customer(int id, const std::string& name, const std::string& phone, const std::string& email);
};

#endif // CUSTOMER_H
