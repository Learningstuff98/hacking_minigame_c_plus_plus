#ifndef _GAME_H_
#define _GAME_H_
#include <vector>

class Game {
  static std::string possible_words [18];
  static std::vector<std::string> random_words;
  static char characters [22];
  int generate_random_number();
  void render_text_walls();

  public:
    Game();
    std::vector<std::string> get_random_words();
};

#endif
