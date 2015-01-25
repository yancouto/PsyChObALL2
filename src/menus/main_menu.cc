#include <menus/main_menu.h>

namespace psy {

MainMenu::MainMenu() : shape_(100.f) {
  // Sets up and adds to the scene a dummy task for testing.
  Task hello_world([this](const sf::Time &dt) {
                      // Every second we print out the FPS.
                      if (fps_counter_ < 1000) {
                        fps_counter_ += dt.asMilliseconds();
                        return;
                      }
                      fps_counter_ = dt.asMilliseconds();
                      printf("dt = %f\n", 1.0f/dt.asSeconds());
                    });
  scene_.AddTask(hello_world);
  // Sets up a Render callback for Scene to render.
  shape_.setPosition(400, 300);           
  shape_.setFillColor(sf::Color::Green);   
  scene_.set_render_callback([this](sf::RenderWindow &canvas) {
                      canvas.draw(shape_);
                    });
  // Adds a Task for basic WASD movement.
  Task move_task([this](const sf::Time &dt) {
                      if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                        shape_.move(0, -2);
                      if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                        shape_.move(-2, 0);
                      if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                        shape_.move(0, 2);
                      if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                        shape_.move(2, 0);
                    });
  scene_.AddTask(move_task);
  // Sets up the Focus callback. When the scene is to become active.
  scene_.set_focus_callback([](const psy::Scene &scene) {
                      puts("Scene has gained focus.");
                    });
  // Sets up the DeFocus callback. When the scene is to become inactive.
  scene_.set_defocus_callback([](const psy::Scene &scene) {
                      puts("Scene has lost focus.");
                    }); 
}

MainMenu::~MainMenu() {}

}  //namespace psy;
