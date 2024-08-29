#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include <mysql/mysql.h>
#include <string>

class DatabaseConnection {
public:
    DatabaseConnection(const std::string& host, const std::string& user, const std::string& password, const std::string& dbname);
    ~DatabaseConnection();

    bool connect();
    MYSQL* getConnection();

private:
    MYSQL* conn;
    std::string host;
    std::string user;
    std::string password;
    std::string dbname;
};

#endif
