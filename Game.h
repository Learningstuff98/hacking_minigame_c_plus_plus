#ifndef _GAME_H_
#define _GAME_H_
#include <vector>

class Game {
  static std::string possible_words [18];
  int generate_random_number();
  public:
    std::vector<std::string> get_random_words();
};

#endif
