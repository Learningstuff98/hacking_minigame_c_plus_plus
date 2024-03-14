#include <iostream>
#include "Game.h"

void Game::say_words() {
  const std::string words [4] {"one", "five", "seven", "ten"};
  for(const std::string &word: words) {
    std::cout << word << std::endl;
  }
};
