//
// Created by noahg on 27.01.2025.
//

#ifndef USER_H
#define USER_H
#include <string>

class User {
private:
    std::string username;
    std::string password;

    public:
    User(std::string username, std::string password);
    User(const User &other);
    std::string getUsername() const;
    std::string getPassword() const;
};

#endif //USER_H
