#ifndef _GAME_H_
#define _GAME_H_
#include <vector>

class Game {
  static std::string possible_words [18];
  static std::vector<std::string> random_words;
  static char characters [22];
  int possible_word_coordinates [3][6][2];
  std::string text_walls;
  std::string set_text_walls();
  void add_text(std::string &text, std::string &result);
  int generate_random_number(int distribution_end);
  std::vector<std::string> get_random_words();

  public:
    Game();
};

#endif
