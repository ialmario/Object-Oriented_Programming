// main.cpp
#include <iostream>
#include "RPG.h"
#include "Game.h"

using namespace std;

int main()
{
    // Create a Game object
    Game game;

    // Set the number of players
    int num_players = 10;

    // Generate the players
    game.generatePlayers(num_players);

    // Run the game
    game.gameLoop();

    // Print the final results
    game.printFinalResults();

    return 0;
}