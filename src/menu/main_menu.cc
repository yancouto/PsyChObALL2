#include <menu/main_menu.h>

#include <SFML/Graphics.hpp>

#include <engine/task.h>

namespace psy {
namespace menu {
namespace {

std::shared_ptr<psy::engine::Scene> menu = nullptr;
sf::CircleShape *circle_shape = nullptr;
int fps_counter = 1;

void CreateMenu() {
  psy::engine::Scene *m = new psy::engine::Scene;  // New menu
  circle_shape = new sf::CircleShape(100.f);

  // Sets up and adds to the scene a dummy task for testing.
  psy::engine::Task hello_world([](const sf::Time &dt) {
    // Every second we print out the FPS.
    if (fps_counter < 1000) {
      fps_counter += dt.asMilliseconds();
      return;
    }
    fps_counter = dt.asMilliseconds();
    printf("dt = %f\n", 1.0f/dt.asSeconds());
  });
  m->AddTask(hello_world);

  // Sets up a Render callback for Scene to render.
  circle_shape->setPosition(400, 300);           
  circle_shape->setFillColor(sf::Color::Green);   
  m->set_render_callback([=](sf::RenderWindow &canvas) {
    canvas.draw(*circle_shape);
  });
  // Adds a Task for basic WASD movement.
  psy::engine::Task move_task([=](const sf::Time &dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
      circle_shape->move(0, -.2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
      circle_shape->move(-.2, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      circle_shape->move(0, .2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
      circle_shape->move(.2, 0);
  });
  m->AddTask(move_task);

  // Sets up the Focus callback. When the scene is to become active.
  m->set_focus_callback([](psy::engine::Scene &self) {
    puts("Scene has gained focus.");
  });

  // Sets up the DeFocus callback. When the scene is to become inactive.
  m->set_defocus_callback([](psy::engine::Scene &self) {
    puts("Scene has lost focus.");
  }); 

  menu.reset(m);
}

}  // unnamed namespace

std::shared_ptr<psy::engine::Scene> MainMenuScene() {
  if (!menu) CreateMenu();
  return menu;
}

}  // namespace menu
}  // namespace psy
