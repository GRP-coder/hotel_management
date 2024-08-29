#include "Authentication.h"
#include <iostream>

Authentication::Authentication(DatabaseConnection* dbConn) : dbConn(dbConn) {}

bool Authentication::login(const std::string& username, const std::string& password) {
    MYSQL* conn = dbConn->getConnection();
    MYSQL_RES* res;
    MYSQL_ROW row;

    std::string query = "SELECT * FROM users WHERE username = '" + username + "' AND password = '" + password + "'";
    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Failed to login\n";
        return false;
    }

    res = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res))) {
        std::cout << "Login successful!\n";
        mysql_free_result(res);
        return true;
    } else {
        std::cerr << "Invalid username or password\n";
        mysql_free_result(res);
        return false;
    }
}
