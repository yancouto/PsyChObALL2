#include "psycho2.h"

#include <cstdio>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "engine/scene.h"

namespace {
// Main game window.
sf::RenderWindow *window = nullptr;
// Active scene.
psy::Scene* active_scene = nullptr;
// Main game clock.
sf::Clock* game_clock = nullptr;
}  // namespace

namespace psy {
namespace system {

void Init() {
  window = new sf::RenderWindow(sf::VideoMode(200, 200), "PsyChObALL 2");
  active_scene = new psy::Scene(); 
  game_clock = new sf::Clock();
}

// Runs the main game loop.
// Order of handling priority:
//  1. Event handling.
//  2. Scene updating.
//  3. Rendering.
// TODO(Renato): Review order of priority.
void Run() {
  // Sets up and adds to the scene a dummy task for testing.
  Task hello_world([](const sf::Time &dt) {
                      printf("dt = %f\n", 1.0f/dt.asSeconds());
                    });
  active_scene->AddTask(hello_world);
  // Sets up a Render callback for Scene to render.
  sf::CircleShape shape(100.f);           
  shape.setFillColor(sf::Color::Green);   
  active_scene->set_render_callback([&shape](sf::RenderWindow &canvas) {
                      canvas.draw(shape);
                    });
  // Sets up the Focus callback. When the scene is to become active.
  active_scene->set_focus_callback([](const psy::Scene &scene) {
                      puts("Scene has gained focus.");
                    });
  // Sets up the DeFocus callback. When the scene is to become inactive.
  active_scene->set_defocus_callback([](const psy::Scene &scene) {
                      puts("Scene has lost focus.");
                    });
  // Starts the scene.
  active_scene->Focus();
  
  game_clock->restart();  // Resets clock to 0.
  while (window->isOpen()) {
    sf::Event event;
    while (window->pollEvent(event)) {  // event handling
      if (event.type == sf::Event::Closed)
        window->close();
    }
    
    active_scene->Update(game_clock->restart());

    window->clear();
    active_scene->Render(*window);
    window->display();
  }
  
  // Finishes the scene.
  active_scene->DeFocus();
}

void Release() {
  if (window) delete window;
  if (active_scene) delete active_scene;
  if (game_clock) delete game_clock;
}

}  // namespace system
}  // namespace psy
