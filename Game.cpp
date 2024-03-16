#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
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

char Game::characters [22] {
  '@',
  '#',
  '$',
  '%',
  '&',
  '*',
  '(',
  ')',
  '{',
  '}',
  '[',
  ']',
  '+',
  '-',
  '=',
  '<',
  '>',
  '/',
  '.',
  ',',
  ':',
  ';'
};

std::vector<std::string> Game::random_words {};

Game::Game() {
  random_words = get_random_words();
  render_text_walls();
};

void Game::render_text_walls() {
  std::cout << "-------------------------------";
  std::cout << std::endl;
  for(size_t height {1}; height <= 17; height++) {
    std::cout << "| ";
    for(size_t width {1}; width <= 12; width++) {
      std::cout << characters[width];
    }
    std::cout << " | ";
    for(size_t width {1}; width <= 12; width++) {
      std::cout << characters[width];
    }
    std::cout << " |";
    std::cout << std::endl;
  }
  std::cout << "-------------------------------";
  std::cout << std::endl;
};

int Game::generate_random_number() {
  // https://www.reddit.com/r/learnprogramming/comments/5uu9eu/generating_random_number_in_c/
  // https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution

  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(0, 17);
  return dist(mt);
};

std::vector<std::string> Game::get_random_words () {
  std::vector<int> random_indexes{};
  int i {1};
  while(i <= 5) {
    int new_random_number {generate_random_number()};
    if(std::count(random_indexes.cbegin(), random_indexes.cend(), new_random_number) == 0) {
      random_indexes.push_back(new_random_number);
      i++;
    }
  }
  std::vector<std::string> random_words {};
  for(auto &random_index: random_indexes) {
    random_words.push_back(possible_words[random_index]);
  }
  return random_words;
};
