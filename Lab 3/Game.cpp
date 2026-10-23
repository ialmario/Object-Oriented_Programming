// Game.cpp
#include "Game.h"
#include "RPG.h"

#include <iostream>
#include <string>
#include <random>
#include <iterator>

using namespace std;

// Constructor
Game::Game()
{
}

// Creates n RPG players
void Game::generatePlayers(int n)
{
    for (int i = 0; i < n; i++)
    {
        players.push_back(new RPG());

        string new_name = "NPC_" + to_string(i);
        players[i]->setName(new_name);

        live_players.insert(i);
    }
}

// Randomly selects a living player
int Game::selectPlayer()
{
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dist(
        0, static_cast<int>(live_players.size()) - 1
    );

    int randomIndex = dist(gen);

    set<int>::iterator it = live_players.begin();
    advance(it, randomIndex);

    return *it;
}

// Updates the winner and removes the loser
void Game::endRound(RPG* winner, RPG* loser, int loserIndex)
{
    winner->setHitsTaken(0);

    live_players.erase(loserIndex);

    winner->updateExpLevel();

    cout << winner->getName()
         << " won against "
         << loser->getName()
         << endl;
}

// Runs one battle
void Game::battleRound()
{
    int playerIndex1 = selectPlayer();
    int playerIndex2 = selectPlayer();

    // Select again if both indices are the same
    if (playerIndex1 == playerIndex2)
    {
        battleRound();
        return;
    }

    RPG* player1 = players[playerIndex1];
    RPG* player2 = players[playerIndex2];

    // Attack until one RPG is defeated
    while (player1->isAlive() && player2->isAlive())
    {
        player1->attack(player2);

        if (player2->isAlive())
        {
            player2->attack(player1);
        }
    }

    // Determine the winner and loser
    if (player1->isAlive())
    {
        endRound(player1, player2, playerIndex2);
    }
    else
    {
        endRound(player2, player1, playerIndex1);
    }
}

// Runs battles until one player remains
void Game::gameLoop()
{
    while (live_players.size() > 1)
    {
        battleRound();
    }
}

// Prints every player's final statistics
void Game::printFinalResults()
{
    for (RPG* player : players)
    {
        player->printStats();
    }
}

// Destructor
Game::~Game()
{
}
