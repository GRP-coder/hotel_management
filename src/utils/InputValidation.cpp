#include "InputValidation.h"
#include <regex>

bool InputValidation::isValidDate(const std::string& date) {
    std::regex dateRegex(R"(\d{4}-\d{2}-\d{2})");
    return std::regex_match(date, dateRegex);
}

bool InputValidation::isValidEmail(const std::string& email) {
    std::regex emailRegex(R"((\w+)(\.{0,1})(\w*)@(\w+)\.(\w+))");
    return std::regex_match(email, emailRegex);
}

bool InputValidation::isValidPhoneNumber(const std::string& phone) {
    std::regex phoneRegex(R"(\d{10})");
    return std::regex_match(phone, phoneRegex);
}