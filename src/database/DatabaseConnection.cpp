#include "DatabaseConnection.h"
#include <iostream>

DatabaseConnection::DatabaseConnection(const std::string& host, const std::string& user, const std::string& password, const std::string& dbname)
    : host(host), user(user), password(password), dbname(dbname), conn(nullptr) {}

DatabaseConnection::~DatabaseConnection() {
    if (conn) {
        mysql_close(conn);
    }
}

bool DatabaseConnection::connect() {
    conn = mysql_init(nullptr);
    if (conn == nullptr) {
        std::cerr << "mysql_init() failed\n";
        return false;
    }

    if (mysql_real_connect(conn, host.c_str(), user.c_str(), password.c_str(), dbname.c_str(), 0, nullptr, 0) == nullptr) {
        std::cerr << "mysql_real_connect() failed\n";
        mysql_close(conn);
        return false;
    }

    return true;
}

MYSQL* DatabaseConnection::getConnection() {
    return conn;
}
