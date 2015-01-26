#include <psycho2.h>

#include <cstdio>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <engine/scene.h>
#include <menus/main_menu.h>

namespace {
// Main game window.
std::unique_ptr<sf::RenderWindow> window (nullptr);
// Current Scene beign update and the next one.
std::shared_ptr<psy::Scene> current_scene (nullptr), next_scene (nullptr);

// Manages Focus and Defocus and changes scenes
void DoSceneChange() {
  if (current_scene) current_scene->DeFocus();
  current_scene = next_scene;
  next_scene = nullptr;
  current_scene->Focus();
}

}  // namespace

namespace psy {
namespace system {

void Init() {
  window.reset(new sf::RenderWindow(sf::VideoMode(800, 600), "PsyChObALL 2"));
}

// Runs the main game loop.
// Order of handling priority:
//  1. Event handling.
//  2. Scene updating.
//  3. Rendering.
// TODO(Renato): Review order of priority.
void Run() {
  sf::Clock loop_clock;
  
  while (window->isOpen()) {
    sf::Event event;
    while (window->pollEvent(event)) {  // Event handling
      if (event.type == sf::Event::Closed)
        window->close();
    }
    

    window->clear();
    if (current_scene) {
      current_scene->Update(loop_clock.restart());
      current_scene->Render(*window);
    }
    window->display();

    if (next_scene) DoSceneChange();
    if (current_scene && current_scene->finished()) break;
    if (!current_scene) break;
  }
  
  // Finishes the scene.
  if (current_scene) current_scene->DeFocus();
}

void Release() {}

void ChangeTo(std::shared_ptr<psy::Scene> scene) {
  if (next_scene) printf("Too much Scene-changing.\n");
  next_scene = scene;
}

}  // namespace system
}  // namespace psy
