//
// Created by noahg on 27.01.2025.
//

#ifndef USER_H
#define USER_H
#include <string>
#include <vector>

#include "Game.h"

class User {
private:
    std::string username;
    std::string password;
    std::vector<Game*> boughtGames;
    int credit;

    public:
    User(std::string username, std::string password, int credit);
    User(const User &other);
    std::string getUsername() const;
    std::string getPassword() const;
    int getCredit() const;
    void removeCredit(int credits);
    bool addGame(Game* game);
    std::vector<Game*> getGames() const;
};


#endif //USER_H
