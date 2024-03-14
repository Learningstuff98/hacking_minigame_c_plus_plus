#include <iostream>
#include "Game.h"

std::string get_desired_operation() {
  std::cout << "Please select one of the following options:" << std::endl;
  std::cout << "start or exit." << std::endl;
  std::string desired_operation {""};
  std::cin >> desired_operation;
  return desired_operation;
};

int main() {
  std::cout << "Hello and welcome to my basic C++ hacking minigame!" << std::endl;
  std::string desired_operation {get_desired_operation()};
  while(desired_operation != "exit") {
    if(desired_operation == "start") {
      Game new_game {};
      new_game.say_words();
      desired_operation = get_desired_operation();
    } else {
      std::cout << "ERROR! ERROR! INVALID SELECTION!" << std::endl;
      desired_operation = get_desired_operation();
    }
  };
  std::cout << "Program shutting down. Goodbye.";
  return 0;
};
