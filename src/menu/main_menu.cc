#include <menu/main_menu.h>

#include <memory>

#include <SFML/Graphics.hpp>

#include <tmx/MapLoader.h>

#include <engine/task.h>
#include <system/globals.h>
#include <system/manager.h>
#include <utils/color.h>

namespace psy {
namespace menu {
namespace {

int fps_counter = 1;
sf::Font nevis;
sf::Text text;
utils::ColorPattern pattern;
std::unique_ptr<tmx::MapLoader> map;

utils::ColorPattern back_pattern(utils::ColorChanger(sf::Color::Blue, 150.));
sf::RectangleShape background;

engine::State *CreateMenu() {
  engine::State *m = new engine::State;  // New menu

  // Font stuff
  nevis.loadFromFile("assets/fonts/nevis.ttf");
  text.setFont(nevis);
  text.setString("PsyChObALL 2222");
  text.setColor(pattern.CurrentColor());
  text.setPosition(10, 5);

  // Background
  background.setPosition(0, 0);
  background.setSize(sf::Vector2f(system::window_size.x, system::window_size.y));
  background.setFillColor(back_pattern.CurrentColor());

  engine::Task color_update([](const sf::Time &dt) {
    text.setColor(pattern.CurrentColor());
    background.setFillColor(back_pattern.CurrentColor());
  });
  m->AddTask(color_update);

  // Map
  map.reset(new tmx::MapLoader("assets/tilemaps"));
  map->Load("hospital.tmx");

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
    canvas.draw(background);
    canvas.draw(*map);
    canvas.draw(*(psy::menu::Player()));
    canvas.draw(text);
  });

  // Sets up the Focus callback. When the state is to become active.
  m->set_focus_callback([](engine::State &self) {
    puts("State has gained focus.");
  });

  // Sets up the DeFocus callback. When the state is to become inactive.
  m->set_defocus_callback([](engine::State &self) {
    puts("State has lost focus.");
  }); 

  return m;
}

entities::Player *CreatePlayer() {
  entities::Player *p = new entities::Player(400.f, 300.f);

  auto current_state = MainMenuState();
  engine::Task player_update([](const sf::Time &dt) {
    psy::menu::Player()->Update(dt);
  });
  current_state->AddTask(player_update);
  
  return p;
}


}  // unnamed namespace

std::shared_ptr<psy::engine::State> MainMenuState() {
  static const std::shared_ptr<engine::State> menu(CreateMenu());
  return menu;
}

std::shared_ptr<psy::entities::Player> Player() {
  static const std::shared_ptr<entities::Player> player(CreatePlayer());
  return player;
}

}  // namespace menu
}  // namespace psy
