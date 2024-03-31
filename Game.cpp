#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include "Game.h"

Game::Game()
  : possible_word_coordinates {
    { {1, 1}, {3, 10}, {9, 14}, {13, 8}, {21, 7}, {16, 16} },
    { {3, 3}, {6, 6}, {8, 17}, {13, 1}, {14, 9}, {21, 17} },
    { {1, 10}, {3, 12}, {2, 15}, {15, 3}, {13, 5}, {14, 6} }
  }, characters {
    '@', '#', '$', '%', '&', '*', '(', ')', '{', '}', '[',
    ']', '+', '-', '=', '<', '>', '/', '.', ',', ':', ';'
  }, possible_words {
    "FOUR", "FIVE", "NINE", "FUZZ", "QUIZ", "BUZZ", "STOP",
    "RAIN", "CANE", "JOKE", "COZY", "WALK", "TALK", "ZINC",
    "FAME", "SLAM", "DUMB", "DOOR"
  }, tries_left {3} {
  random_words = get_random_words();
  password = random_words[generate_random_number(5)];
  text_walls = set_text_walls();
  std::cout << text_walls;
  handle_input_flow();
};

void Game::handle_input_flow() {
  std::string game_input {get_game_input()};
  while(game_input != "exit") {
    if(std::count(random_words.cbegin(), random_words.cend(), game_input) == 1) {
      std::cout << text_walls << std::endl;
      if(game_input == password) {
        std::cout << "You've hacked the terminal!" << std::endl;
        break;
      } else {
        std::cout << "Wrong word. Try again." << std::endl;
      }
      game_input = get_game_input();
    } else {
      std::cout << text_walls << std::endl;
      std::cout << "ERROR! ERROR! INVALID SELECTION!" << std::endl;
      game_input = get_game_input();
    }
  }
  std::cout << "Ending game and returning to the main menu." << std::endl;
}

void Game::display_remaining_tries() {
  std::cout << "Tries left: ";
  for(int i {1}; i <= tries_left; i++) {
    std::cout << "* ";
  }
  std::cout << std::endl;
}

std::string Game::get_game_input() {
  display_remaining_tries();
  std::cout << "Please enter a word, or exit to go back to the main menu." << std::endl;
  std::string game_input{""};
  std::cin >> game_input;
  return game_input;
}

void Game::add_text(const std::string &text, std::string &result) {
  for(auto &text_char: text) {
    result.push_back(text_char);
  };
};

std::string Game::set_text_walls() {
  std::string result {""};
  auto coordinate_list {possible_word_coordinates[generate_random_number(2)]};
  std::string dash_line {"-------------------------------"};
  add_text(dash_line, result);
  result.push_back('\n');
  for(int y {1}; y <= 17; y++) {
    std::string leading_pipe {"| "};
    add_text(leading_pipe, result);
    int x {1};
    while(x <= 12) {
      if(x == coordinate_list[0][0] && y == coordinate_list[0][1]) {
        add_text(random_words[0], result);
        x += 4;
      } else if(x == coordinate_list[1][0] && y == coordinate_list[1][1]) {
        add_text(random_words[1], result);
        x += 4;
      } else if(x == coordinate_list[2][0] && y == coordinate_list[2][1]) {
        add_text(random_words[2], result);
        x += 4;
      } else {
        result.push_back(characters[generate_random_number(21)]);
        x++;
      }
    }
    std::string middle_pipe {" | "};
    add_text(middle_pipe, result);
    while(x <= 24) {
      if(x == coordinate_list[3][0] && y == coordinate_list[3][1]) {
        add_text(random_words[3], result);
        x += 4;
      } else if(x == coordinate_list[4][0] && y == coordinate_list[4][1]) {
        add_text(random_words[4], result);
        x += 4;
      } else if(x == coordinate_list[5][0] && y == coordinate_list[5][1]) {
        add_text(random_words[5], result);
        x += 4;
      } else {
        result.push_back(characters[generate_random_number(21)]);
        x++;
      }
    }
    std::string ending_pipe {" |"};
    add_text(ending_pipe, result);
    result.push_back('\n');
  }
  add_text(dash_line, result);
  result.push_back('\n');
  return result;
};

int Game::generate_random_number(const int distribution_end) {
  // https://www.reddit.com/r/learnprogramming/comments/5uu9eu/generating_random_number_in_c/
  // https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution

  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(0, distribution_end);
  return dist(mt);
};

std::vector<std::string> Game::get_random_words() {
  std::vector<std::string> random_words {};
  int i {1};
  while(i <= 6) {
    std::string new_random_word {possible_words[generate_random_number(17)]};
    if(std::count(random_words.cbegin(), random_words.cend(), new_random_word) == 0) {
      random_words.push_back(new_random_word);
      i++;
    }
  }
  return random_words;
};
