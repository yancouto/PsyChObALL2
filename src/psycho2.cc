#include <psycho2.h>

#include <cstdio>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <engine/scene.h>
#include <menus/main_menu.h>

namespace {
// Main game window.
sf::RenderWindow *window = nullptr;
// Main game clock.
sf::Clock *game_clock = nullptr;
// Main menu.
psy::MainMenu *main_menu = nullptr;
}  // namespace

namespace psy {
namespace system {

void Init() {
  window = new sf::RenderWindow(sf::VideoMode(800, 600), "PsyChObALL 2");
  game_clock = new sf::Clock();
  main_menu = new psy::MainMenu();
}

// Runs the main game loop.
// Order of handling priority:
//  1. Event handling.
//  2. Scene updating.
//  3. Rendering.
// TODO(Renato): Review order of priority.
void Run() {
  // This is the scene that we are currently updating and drawing.
  Scene &active_scene(main_menu->scene());

  // Starts the scene.
  active_scene.Focus();
  
  game_clock->restart();  // Resets clock to 0.
  while (window->isOpen()) {
    sf::Event event;
    while (window->pollEvent(event)) {  // event handling
      if (event.type == sf::Event::Closed)
        window->close();
    }
    
    active_scene.Update(game_clock->restart());

    window->clear();
    active_scene.Render(*window);
    window->display();
  }
  
  // Finishes the scene.
  active_scene.DeFocus();
}

void Release() {
  if (window) delete window;
  if (game_clock) delete game_clock;
  if (main_menu) delete main_menu;
}

}  // namespace system
}  // namespace psy
