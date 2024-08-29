#ifndef CUSTOMER_UI_H
#define CUSTOMER_UI_H

#include "CustomerManager.h"

class CustomerUI {
public:
    CustomerUI(CustomerManager* customerManager);
    void addCustomer();
    void updateCustomer();
    void deleteCustomer();
    void displayCustomer(int customerId);

private:
    CustomerManager* customerManager;
};

#endif
