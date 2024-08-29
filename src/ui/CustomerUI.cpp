#include "CustomerUI.h"
#include <iostream>

CustomerUI::CustomerUI(CustomerManager* customerManager) : customerManager(customerManager) {}

void CustomerUI::addCustomer() {
    Customer customer;
    std::cout << "Enter Customer Name: ";
    std::cin >> customer.name;
    std::cout << "Enter Customer Phone: ";
    std::cin >> customer.phone;
    std::cout << "Enter Customer Email: ";
    std::cin >> customer.email;

    customerManager->addCustomer(customer);
    std::cout << "Customer added successfully.\n";
}

void CustomerUI::updateCustomer() {
    Customer customer;
    std::cout << "Enter Customer ID: ";
    std::cin >> customer.id;
    std::cout << "Enter New Customer Name: ";
    std::cin >> customer.name;
    std::cout << "Enter New Customer Phone: ";
    std::cin >> customer.phone;
    std::cout << "Enter New Customer Email: ";
    std::cin >> customer.email;

    customerManager->updateCustomer(customer);
    std::cout << "Customer updated successfully.\n";
}

void CustomerUI::deleteCustomer() {
    int customerId;
    std::cout << "Enter Customer ID to delete: ";
    std::cin >> customerId;

    customerManager->deleteCustomer(customerId);
    std::cout << "Customer deleted successfully.\n";
}

void CustomerUI::displayCustomer(int customerId) {
    Customer customer = customerManager->getCustomerById(customerId);
    std::cout << "Customer ID: " << customer.id << ", Name: " << customer.name << ", Phone: " << customer.phone << ", Email: " << customer.email << "\n";
}
