#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "global.hpp"
#include "statistics.hpp"

struct Score {
    std::string name;
    ull score;
    bool win;
    ull largestTile;
    long long moveCount;
    double duration;
};

bool operator < (const Score&lhs, const Score &rhs) {
  return lhs.score < rhs.score;
}

class Scoreboard {
    private:
        std::string name;
        std::vector<Score> scoreList;
        void prompt();
        void writeToFile();
        void readFile();
        void padding(std::string name);

    public:
        unsigned long long score = 0;
        bool win;
        unsigned long long largestTile;
        long long moveCount;
        double duration;
        void printScore();
        void printStats();
        void save();
};

void Scoreboard::prompt() {

    std::cout << bold_on << "  Please enter your name to save this score: " << bold_off;
    std::cin >> name;

}

void Scoreboard::writeToFile() {

    std::fstream scores("./data/scores.txt", std::ios_base::app);
    scores << std::endl << name << " " << score << " " << win << " " << moveCount << " " << largestTile << " " << duration; endl();
    scores.close();

}

void Scoreboard::printScore() {

    readFile();

    clearScreen();
    drawAscii();
    std::cout << green << bold_on << "  SCOREBOARD" << bold_off << def; endl();
    std::cout << green << bold_on << "  ----------" << bold_off << def; endl(2);

    std::size_t size = scoreList.size();

    for (std::size_t i = size - 1; i >= 0; --i) {
      const auto& player = scoreList[i];
      std::string won = player.win ? "Yes" : "No";

        if (i == size - 1) {
            std::cout << "  +-----+--------------------+----------+------+-------+--------------+--------------+"; endl();
            std::cout << "  | " << bold_on << "No." << bold_off << " | "
                        << bold_on << "Name" << bold_off << "               | "
                        << bold_on << "Score" << bold_off << "    | "
                        << bold_on << "Won?" << bold_off << " | "
                        << bold_on << "Moves" << bold_off << " | "
                        << bold_on << "Largest Tile" << bold_off << " | "
                        << bold_on << "Duration (s)" << bold_off << " |";
            endl();
            std::cout << "  +-----+--------------------+----------+------+-------+--------------+--------------+"; endl();
        }

        std::cout << "  | " << std::setw(2) << size - i << ". | " 
                            << player.name; padding(player.name);
        std::cout << " | " << std::setw(8) << player.score << " | "
                            << std::setw(4) << won << " | "
                            << std::setw(5) << player.moveCount << " | "
                            << std::setw(12) << player.largestTile << " | "
                            << std::setw(12) << player.duration << " | ";
        endl();
    }

    if (!size) {
        std::cout << "  No saved scores.";
        endl();
    }
    else {
        std::cout << "  +-----+--------------------+----------+------+-------+--------------+--------------+";
    }

    endl(3);

}

void Scoreboard::printStats() {

    Stats stats;
    stats.collectStatistics();
    std::cout << green << bold_on << "  STATISTICS" << bold_off << def; endl();
    std::cout << green << bold_on << "  ----------" << bold_off << def; endl(2);
    std::cout << "  +--------------------+------------+"; endl();
    std::cout << "  | " << bold_on << "Best Score        " << bold_off << " | " << std::setw(10) << stats.bestScore << " |"; endl();
    std::cout << "  | " << bold_on << "Game Count        " << bold_off << " | " << std::setw(10) << stats.gameCount << " |"; endl();
    std::cout << "  | " << bold_on << "Number of Wins    " << bold_off << " | " << std::setw(10) << stats.winCount << " |"; endl();
    std::cout << "  | " << bold_on << "Total Moves Played" << bold_off << " | " << std::setw(10) << stats.totalMoveCount << " |"; endl();
    std::cout << "  | " << bold_on << "Total Duration (s)" << bold_off << " | " << std::setw(10) << stats.totalDuration << " |"; endl();
    std::cout << "  +--------------------+------------+"; endl();
    
    endl(3);

    std::cout << "  Press any key to exit: ";
    char c;
    std::cin >> c;
    exit(1);

}

void Scoreboard::padding(std::string str) {

    int length = str.length();
    while (18 - length++) {
        std::cout << " ";
    }

}

void Scoreboard::readFile() {

    std::ifstream scores("./data/scores.txt");

    std::string playerName;
    ull playerScore;
    bool playerStatus;
    ull playerLargestTile;
    long long playerMoveCount;
    double playerDuration;

    while (scores >> playerName >> playerScore >> playerStatus >> playerMoveCount >> playerLargestTile >> playerDuration) {

        Score bufferScore;
        bufferScore.name = playerName;
        bufferScore.score = playerScore;
        bufferScore.win = playerStatus;
        bufferScore.largestTile = playerLargestTile;
        bufferScore.moveCount = playerMoveCount;
        bufferScore.duration = playerDuration;

        scoreList.push_back(bufferScore);

    };

    std::sort(scoreList.begin(), scoreList.end());

}

void Scoreboard::save() {

    prompt();
    writeToFile();
    std::cout << green << bold_on << "  Score saved!" << bold_off << def; endl();

}