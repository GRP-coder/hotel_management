#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#include <string>

class InputValidation {
public:
    static bool isValidDate(const std::string& date);
    static bool isValidEmail(const std::string& email);
    static bool isValidPhoneNumber(const std::string& phone);
};

#endif
