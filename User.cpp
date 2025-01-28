//
// Created by noahg on 27.01.2025.
//

#include "User.h"

User::User(std::string username, std::string password) : username(username), password(password) {}
User::User(const User& other) : username(other.username), password(other.password) {}

std::string User::getUsername() const {
    return username;
}
std::string User::getPassword() const {
    return password;
}