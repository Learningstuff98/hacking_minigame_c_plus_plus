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

int Game::generate_random_number() {
  // https://www.reddit.com/r/learnprogramming/comments/5uu9eu/generating_random_number_in_c/
  // https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution

  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(0, 17);
  return dist(mt);
};

void Game::print_random_words () {
  // Shouldn't print the same word more than once
  for(size_t i {1}; i <= 5; i++) {
    std::cout << possible_words[generate_random_number()] << std::endl;
  }
};
