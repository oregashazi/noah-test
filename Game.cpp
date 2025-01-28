//
// Created by noahg on 27.01.2025.
//

#include "Game.h"
#include <iostream>
using namespace std;

int Game::nexid = 1;

Game::Game(std::string title, int price) : title(title), price(price) {
    id = nexid++;
}

Game::Game(const Game &game)
    : title(game.title), price(game.price), id(game.id) {

}

 int Game::getId() const {
    return id;
}

int Game::getPrice() const {
    return price;
}

std::string Game::getTitle() const {
    return title;
}