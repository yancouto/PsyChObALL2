#include <menu/main_menu.h>

#include <SFML/Graphics.hpp>

#include <engine/task.h>
#include <entities/player.h>
#include <system/psycho2.h>

namespace psy {
namespace menu {
namespace {

std::shared_ptr<psy::engine::Scene> menu = nullptr;
std::shared_ptr<psy::entities::Player> player = nullptr;
int fps_counter = 1;

void CreateMenu() {
  engine::Scene *m = new engine::Scene;  // New menu

  // Sets up and adds to the scene a dummy task for testing.
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

  // Sets up Scene Rendering callback.
  m->set_render_callback([](sf::RenderWindow &canvas) {
    canvas.draw(*(psy::menu::Player()));
  });

  // Sets up the Focus callback. When the scene is to become active.
  m->set_focus_callback([](engine::Scene &self) {
    puts("Scene has gained focus.");
  });

  // Sets up the DeFocus callback. When the scene is to become inactive.
  m->set_defocus_callback([](engine::Scene &self) {
    puts("Scene has lost focus.");
  }); 

  menu.reset(m);
}

void CreatePlayer() {
  entities::Player *p = new entities::Player(400.f, 300.f);

  auto current_scene = MainMenuScene();
  engine::Task player_update([](const sf::Time &dt) {
    psy::menu::Player()->Update(dt);
  });
  current_scene->AddTask(player_update);
  
  player.reset(p);
}


}  // unnamed namespace

std::shared_ptr<psy::engine::Scene> MainMenuScene() {
  if (!menu) CreateMenu();
  return menu;
}

std::shared_ptr<psy::entities::Player> Player() {
  if (!player) CreatePlayer();
  return player;
}

}  // namespace menu
}  // namespace psy
