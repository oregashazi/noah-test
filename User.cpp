//
// Created by noahg on 27.01.2025.
//

#include "User.h"

User::User(std::string username, std::string password, int credit) : username(username), password(password), credit(credit) {}
User::User(const User& other) : username(other.username), password(other.password), credit(other.credit) {}

std::string User::getUsername() const {
    return username;
}
std::string User::getPassword() const {
    return password;
}

int User::getCredit() const {
    return credit;
}

void User::removeCredit(int credits) {
    credit -= credits;
}

bool User::addGame(Game game) {
    boughtGames.push_back(&game);
    return true;
}

std::vector<Game *> User::getGames() const {
    return boughtGames;
}

