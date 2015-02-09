#include <menu/main_menu.h>

#include <SFML/Graphics.hpp>

#include <engine/task.h>
#include <system/manager.h>

namespace psy {
namespace menu {
namespace {

std::shared_ptr<psy::engine::State> menu = nullptr;
std::shared_ptr<psy::entities::Player> player = nullptr;
int fps_counter = 1;

void CreateMenu() {
  engine::State *m = new engine::State;  // New menu

  // Sets up and adds to the state a dummy task for testing.
  engine::Task hello_world([](const sf::Time &dt) {
    // Every second we print out the FPS.
    if (fps_counter < 1000) {
      fps_counter += dt.asMilliseconds();
      return;
    }
    fps_counter = dt.asMilliseconds();
    printf("dt = %f\n", 1.0f/dt.asSeconds());
  });
  m->AddTask(hello_world);

  // Sets up State Rendering callback.
  m->set_render_callback([](sf::RenderWindow &canvas) {
    canvas.draw(*(psy::menu::Player()));
  });

  // Sets up the Focus callback. When the state is to become active.
  m->set_focus_callback([](engine::State &self) {
    puts("State has gained focus.");
  });

  // Sets up the DeFocus callback. When the state is to become inactive.
  m->set_defocus_callback([](engine::State &self) {
    puts("State has lost focus.");
  }); 

  menu.reset(m);
}

void CreatePlayer() {
  entities::Player *p = new entities::Player(400.f, 300.f);

  auto current_state = MainMenuState();
  engine::Task player_update([](const sf::Time &dt) {
    psy::menu::Player()->Update(dt);
  });
  current_state->AddTask(player_update);
  
  player.reset(p);
}


}  // unnamed namespace

std::shared_ptr<psy::engine::State> MainMenuState() {
  if (!menu) CreateMenu();
  return menu;
}

std::shared_ptr<psy::entities::Player> Player() {
  if (!player) CreatePlayer();
  return player;
}

}  // namespace menu
}  // namespace psy
