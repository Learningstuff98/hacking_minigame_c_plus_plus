#ifndef _GAME_H_
#define _GAME_H_
#include <vector>

class Game {
  static std::string possible_words [18];
  static std::vector<std::string> random_words;
  static char characters [22];
  int possible_word_coordinates [2][6][2] {
    { {1, 1}, {3, 10}, {9, 14}, {13, 8}, {21, 7}, {16, 16} },
    { {3, 3}, {6, 6}, {8, 17}, {13, 1}, {14, 9}, {21, 17} }
  };
  std::string text_walls;
  std::string set_text_walls();
  void add_text(std::string &text, std::string &result);
  int generate_random_number(int distribution_end);

  public:
    Game();
    std::vector<std::string> get_random_words(); // should make this private at some point
};

#endif
