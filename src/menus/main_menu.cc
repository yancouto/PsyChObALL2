#include <menus/main_menu.h>

#include <SFML/Graphics.hpp>

#include <engine/task.h>

namespace {
std::shared_ptr<psy::Scene> menu = nullptr;
sf::CircleShape *cs = nullptr;

void CreateMenu() {
  psy::Scene *m = new psy::Scene;  // New menu
  cs = new sf::CircleShape(100.f);

  // Sets up and adds to the scene a dummy task for testing.
  psy::Task hello_world([](const sf::Time &dt) {
    // Every second we print out the FPS.
    printf("dt = %f\n", 1.0f/dt.asSeconds());
  });
  m->AddTask(hello_world);

  // Sets up a Render callback for Scene to render.
  cs->setPosition(400, 300);           
  cs->setFillColor(sf::Color::Green);   
  m->set_render_callback([=](sf::RenderWindow &canvas) {
    canvas.draw(*cs);
  });
  // Adds a Task for basic WASD movement.
  psy::Task move_task([=](const sf::Time &dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
      cs->move(0, -.2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
      cs->move(-.2, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      cs->move(0, .2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
      cs->move(.2, 0);
  });
  m->AddTask(move_task);

  // Sets up the Focus callback. When the scene is to become active.
  m->set_focus_callback([](psy::Scene &self) {
    puts("Scene has gained focus.");
  });

  // Sets up the DeFocus callback. When the scene is to become inactive.
  m->set_defocus_callback([](psy::Scene &self) {
    puts("Scene has lost focus.");
  }); 

  menu.reset(m);
}

}  // unnamed namespace

namespace psy {

std::shared_ptr<psy::Scene> MainMenuScene() {
  if (!menu) CreateMenu();
  return menu;
}

}  //namespace psy
