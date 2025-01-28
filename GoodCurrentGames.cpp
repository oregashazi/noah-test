//
// Created by noahg on 27.01.2025.
//

#include "GoodCurrentGames.h"

#include <iostream>
#include <ostream>

#include "Game.h"
using namespace std;
bool GoodCurrentGames::addGame(const Game& game) {
    for (auto& element : games) {
        if (element.getId() == game.getId()) {
            return false;
        }
    }

    games.push_back(game);
    return true;
}

bool GoodCurrentGames::addUser(const User &user) {
    for (auto& element : users) {
        if (element.getUsername() == user.getUsername()) {
            return false;
        }
    }
    users.push_back(user);
    return true;
}

bool GoodCurrentGames::login(std::string username, std::string password) {
    for (auto& element : users) {
        if (element.getUsername() == username) {
            if (element.getPassword() == password) {
                return true;
            }
        }
    }
    return false;
}


std::vector<User> GoodCurrentGames::getUsers() {
    return users;
}

std::vector<Game> GoodCurrentGames::getGames() {
    return games;
}

User& GoodCurrentGames::user(std::string username) {
    for (auto& user : users) {
        if (user.getUsername() == username) {
            return user;
        }
    }
}
