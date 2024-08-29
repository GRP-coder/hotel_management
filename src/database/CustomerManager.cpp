#include "CustomerManager.h"
#include <iostream>

CustomerManager::CustomerManager(DatabaseConnection* dbConn) : dbConn(dbConn) {}

void CustomerManager::addCustomer(const Customer& customer) {
    MYSQL* conn = dbConn->getConnection();
    std::string query = "INSERT INTO customers (name, phone, email) VALUES ('" + customer.name + "', '" + customer.phone + "', '" + customer.email + "')";
    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Failed to add customer\n";
    }
}

Customer CustomerManager::getCustomerById(int customerId) {
    MYSQL* conn = dbConn->getConnection();
    MYSQL_RES* res;
    MYSQL_ROW row;
    Customer customer;

    std::string query = "SELECT * FROM customers WHERE id = " + std::to_string(customerId);
    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Failed to fetch customer\n";
        return customer;
    }

    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);

    if (row) {
        customer.id = atoi(row[0]);
        customer.name = row[1];
        customer.phone = row[2];
        customer.email = row[3];
    }

    mysql_free_result(res);
    return customer;
}

void CustomerManager::updateCustomer(const Customer& customer) {
    MYSQL* conn = dbConn->getConnection();
    std::string query = "UPDATE customers SET name = '" + customer.name + "', phone = '" + customer.phone + "', email = '" + customer.email + "' WHERE id = " + std::to_string(customer.id);
    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Failed to update customer\n";
    }
}

void CustomerManager::deleteCustomer(int customerId) {
    MYSQL* conn = dbConn->getConnection();
    std::string query = "DELETE FROM customers WHERE id = " + std::to_string(customerId);
    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Failed to delete customer\n";
    }
}
