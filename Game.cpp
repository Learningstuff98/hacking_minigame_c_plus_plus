#include <iostream>
#include <random>
#include "Game.h"

std::string Game::possible_words [18] {
  "four",
  "five",
  "nine",
  "fuzz",
  "quiz",
  "buzz",
  "stop",
  "rain",
  "cane",
  "joke",
  "cozy",
  "walk",
  "talk",
  "zinc",
  "fame",
  "slam",
  "dumb",
  "door"
};

void Game::print_random_words () {
  // Note to self: Research more about random number generation with C++.
  // https://www.reddit.com/r/learnprogramming/comments/5uu9eu/generating_random_number_in_c/

  // No dublicate numbers should be allowd

  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(0, 17);

  for(size_t i {1}; i <= 5; i++) {
    std::cout << possible_words[dist(mt)] << std::endl;
  }
};
