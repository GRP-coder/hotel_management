#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <string>

class Authentication {
public:
    bool login(const std::string& username, const std::string& password);
    void logout();
    bool isLoggedIn() const;

private:
    bool loggedIn;
};

#endif
