//
// Created by noahg on 27.01.2025.
//

#ifndef GAME_H
#define GAME_H
#include <string>

class Game {

    private:
    int id;
    std::string title;
    int price;
    static int nexid;

    public:

    Game(std::string title, int price);
    Game(const Game &game);
    int getId() const;
    std::string getTitle() const;
    int getPrice() const;

};

#endif //GAME_H
