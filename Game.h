#ifndef _GAME_H_
#define _GAME_H_
#include <vector>

class Game {
  static std::string possible_words [18];
  int generate_random_number();
  static std::vector<std::string> random_words;
  public:
    Game();
    std::vector<std::string> get_random_words();
};

#endif
