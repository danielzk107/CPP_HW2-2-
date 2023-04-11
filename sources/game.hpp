
#include <list>
#include <utility>
#include <string>
#include "player.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;


namespace ariel{
    class Game;
}

class ariel::Game{
    public:
        int turn;
        std::list<std::pair<Card, Card>> turns;
        Player *p1, *p2;
        std::string winner;
        int num_of_draws;
        int carry_from_draw; // Each draw requires the players to place more cards upside down. This variable will count the number of upside down cards required.

        Game(Player &other_p1, Player &other_p2);

        void playTurn();
        void playAll();// Calls playTurn in a while loop until one of the players reaches 0 cards
        void printWiner(); // Typo; Should be winner
        void printLastTurn(); // Prints turn.top and the result of it.
        void printLog();
        void printStats();
        void ShuffleDeck(Player *p1, Player *p2);


};