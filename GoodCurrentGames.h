//
// Created by noahg on 27.01.2025.
//

#ifndef GOODCURRENTGAMES_H
#define GOODCURRENTGAMES_H
#include <vector>

#include "Game.h"
#include "User.h"

class GoodCurrentGames {
    private:
    std::vector<Game> games;
    std::vector<User> users;
public:
    bool addGame(const Game& game);
    bool addUser(const User& user);
    bool login(std::string username, std::string password);
    User& user(std::string username);
    std::vector<User> getUsers();
    std::vector<Game> getGames();
};

#endif //GOODCURRENTGAMES_H
