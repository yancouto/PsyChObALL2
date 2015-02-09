#include <system/manager.h>

#include <cassert>
#include <cstdio>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <system/globals.h>

namespace {
// Main game window.
std::unique_ptr<sf::RenderWindow> window (nullptr);
// Current State beign update and the next one.
std::shared_ptr<psy::engine::State> current_state (nullptr), 
                                    next_state (nullptr);

// Manages Focus and Defocus and changes states
void DoStateChange() {
  if (current_state) current_state->DeFocus();
  current_state = next_state;
  next_state = nullptr;
  current_state->Focus();
}

}  // namespace

namespace psy {
namespace system {

void Init() {
  window.reset(new sf::RenderWindow(sf::VideoMode(
    window_size.x, window_size.y), 
    "PsyChObALL 2", sf::Style::Default,
    sf::ContextSettings(0, 0, 8, 2, 0)));  // Only change antialiasing level.
  window->setVerticalSyncEnabled(true);
  window->setFramerateLimit(60);
  window->setPosition(sf::Vector2<int>(
    (desktop_resolution.x-window_size.x)/2, 
    (desktop_resolution.y-window_size.y)/2));
}

// Runs the main game loop.
// Order of handling priority:
//  1. Event handling.
//  2. State updating.
//  3. Rendering.
// TODO(Renato): Review order of priority.
void Run() {
  sf::Clock loop_clock;
  
  while (window->isOpen()) {
    sf::Event event;
    while (window->pollEvent(event)) {  // Event handling
      if (event.type == sf::Event::Closed)
        window->close();

      if (event.type == sf::Event::MouseMoved) {
        mouse_position.x = event.mouseMove.x;
        mouse_position.y = event.mouseMove.y;
      }
    }
    

    window->clear();
    if (current_state) {
      current_state->Update(loop_clock.restart());
      current_state->Render(*window);
    }
    window->display();

    if (next_state) DoStateChange();
    if (current_state && current_state->finished()) break;
    if (!current_state) break;
  }
  
  // Finishes the state.
  if (current_state) current_state->DeFocus();
}

void Release() {}

void ChangeTo(std::shared_ptr<psy::engine::State> state) {
  assert(!next_state);  // Too much State changing!
  next_state = state;
}

}  // namespace system
}  // namespace psy
