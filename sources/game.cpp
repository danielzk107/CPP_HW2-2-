#include "game.hpp"
using namespace ariel;

Game::Game(Player &other_p1, Player &other_p2)
{
    p1 = &other_p1;
    p2 = &other_p2;
    turn = 0;
    num_of_draws = 0;
    winner = "No one";
    std::list<std::pair<Card, Card>> turns(0);
    ShuffleDeck(p1, p2);
}
void Game::playTurn()
{
    turn++;
    cout << p1->name << " plays " << p1->TopCard() << " , ";
    cout << p2->name << " plays " << p2->TopCard() << endl;
    turns.assign(1, std::pair<Card, Card>(p1->last_played, p2->last_played));
    if (p1->last_played.Winning(p2->last_played) == 1)
    {
        if (p2->last_played.value == 1)
        {
            if (p1->last_played.value == 2)
            { // P1 wins
                p1->cardswon_arr[p1->cardswon] = p2->last_played;
                p1->cardswon++;
                cout << p1->name << " wins." << endl;
                num_of_draws = 0; // Resetting the number of consecutive draws
            }
            else
            {
                p2->cardswon_arr[p2->cardswon] = p1->last_played;
                p2->cardswon++;
                cout << p2->name << " wins." << endl;
                num_of_draws = 0; // Resetting the number of consecutive draws
            }
        }
        else
        {
            p1->cardswon_arr[p1->cardswon] = p2->last_played;
            p1->cardswon++;
            cout << p1->name << " wins." << endl;
            num_of_draws = 0; // Resetting the number of consecutive draws
        }
    }
    else if(p1->last_played.Winning(p2->last_played) == 0){
        cout << "Draw." << endl; 
        num_of_draws++;
    }
    else
    {
        p2->cardswon_arr[p2->cardswon] = p1->last_played;
        p2->cardswon++;
        cout << p2->name << " wins." << endl;
        num_of_draws = 0; // Resetting the number of consecutive draws
    }
}
void Game::playAll()
{
    // Calls playTurn in a while loop until one of the players reaches 0 cards
}
void Game::printLog()
{
    if (turns.size() < 1)
    {
        printf("Game not played\n");
    }
    for (int i = 0; i < turns.size(); i++)
    {
        // print turns[i] and the result of it.
    }
}
void Game::printWiner(){
    
} // Typo; Should be winner
void Game::printLastTurn(){

}
void Game::printStats(){

}
void Game::ShuffleDeck(Player *p1, Player *p2) // Shuffles a deck and splits it between the two players
{
    srand((unsigned int)time(NULL)); // Setting a random seed to get different results each time
    Card cards[52];
    int count = 0;
    string types[4] = {"Hearts", "Clubs", "Diamonds", "Spades"};
    for (int i = 1; i < 14; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cards[count] = Card(i, types[j]);
            count++;
        }
    }
    for (int j = 0; j < 3; j++) // Shuffling three times
    {
        for (int i = 0; i < 52; i++)
        {
            int newPlace = rand() % 52;
            Card temp = cards[newPlace];
            cards[newPlace] = cards[i];
            cards[i] = temp;
        }
    }
    Card p1Cards[52];
    Card p2Cards[52];
    for(int i = 0; i < 52; i++){
        if(i < 26){
            p1Cards[i] = cards[i];
            p2Cards[1 +26] = Card();
        }
        else{
            p2Cards[i%26] = cards[i];
            p1Cards[i] = Card();
        }
    }
    p1->setCards(p1Cards);
    p2->setCards(p2Cards);
}
