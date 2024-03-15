#ifndef _GAME_H_
#define _GAME_H_
#include <vector>

class Game {
  // data members
  static std::string possible_words [18];
  static std::vector<std::string> random_words;
  static char characters [22];

  // member methods
  int generate_random_number();
  void render_grid();

  public:
    Game();
    std::vector<std::string> get_random_words();
};

#endif
