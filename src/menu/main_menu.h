// This module has the contents of the game's main menu.
// @see State

#ifndef PSY_MENU_MAIN_MENU_H_
#define PSY_MENU_MAIN_MENU_H_ 

#include <forward_list>
#include <memory>

#include <SFML/Graphics.hpp>

#include <engine/state.h>
#include <entities/player.h>

namespace psy {
namespace menu {

// Returns the Main Menu State, that handles all drawable and stuff for the menu
std::shared_ptr<engine::State> MainMenuState(void);

std::shared_ptr<entities::Player> Player(void);

}  // namespace menus
}  // namespace psy

#endif  // PSY_MENU_MAIN_MENU_H_
