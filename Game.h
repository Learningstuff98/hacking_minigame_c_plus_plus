#ifndef _GAME_H_
#define _GAME_H_
#include <vector>

class Game {
  std::vector<std::string> random_words;
  int possible_word_coordinates [3][6][2];
  char characters [22];
  std::string possible_words [18];
  std::string text_walls;
  std::string password;
  int tries_left;
  void display_remaining_tries();
  std::string set_text_walls();
  std::string get_game_input();
  void add_text(const std::string &text, std::string &result);
  void handle_input_flow();
  int generate_random_number(const int distribution_end);
  std::vector<std::string> get_random_words();

  public:
    Game();
};

#endif
