#include "Customer.h"

Customer::Customer() : id(0), name(""), phone(""), email("") {}

Customer::Customer(int id, const std::string& name, const std::string& phone, const std::string& email)
    : id(id), name(name), phone(phone), email(email) {}
