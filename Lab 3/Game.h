// Game.h
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <set>
#include "RPG.h"

using namespace std;

class Game
{
public:
    // Constructor
    Game();

    // Creates the RPG players
    void generatePlayers(int n);

    // Randomly selects a living player
    int selectPlayer();

    // Completes one battle
    void endRound(RPG* winner, RPG* loser, int loserIndex);

    // Runs one battle round
    void battleRound();

    // Runs the game until one player remains
    void gameLoop();

    // Prints every player's final statistics
    void printFinalResults();

    // Destructor
    ~Game();

private:
    // Stores pointers to all RPG players
    vector<RPG*> players;

    // Stores the indices of living players
    set<int> live_players;
};

#endif