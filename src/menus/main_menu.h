// This module has the contents of the game's main menu.
// @see Scene

#ifndef PSYCHO2_MENU_MAIN_MENU_H_
#define PSYCHO2_MENU_MAIN_MENU_H_ 

#include <forward_list>

#include <SFML/Graphics.hpp>

#include <engine/scene.h>

namespace psy {

// TODO: Change this to a namespace or something like that
// This is the class that handles the scene and drawable elements inside the
// main menu.
class MainMenu {
 public:
  MainMenu();
  virtual ~MainMenu();

  Scene& scene() { return scene_; }
  int fps_counter() { return 1.0/fps_counter_; }

 private:
  int fps_counter_ {1};
  Scene scene_;

  // Testing purposes only.
  sf::CircleShape shape_;
};

}  // namespace psy

#endif  // PSYCHO2_MENU_MAIN_MENU_H_
