// This module has the contents of the game's main menu.
// @see Scene

#ifndef PSYCHO2_MENU_MAIN_MENU_H_
#define PSYCHO2_MENU_MAIN_MENU_H_ 

#include <forward_list>
#include <memory>

#include <SFML/Graphics.hpp>

#include <engine/scene.h>

namespace psy {

// Returns the Main Menu Scene, that handles all drawable and stuff for the menu
std::shared_ptr<Scene> MainMenuScene();

}  // namespace psy

#endif  // PSYCHO2_MENU_MAIN_MENU_H_
