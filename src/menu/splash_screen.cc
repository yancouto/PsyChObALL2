#include <menu/splash_screen.h>

#include <SFML/Graphics.hpp>

#include <menu/main_menu.h>
#include <engine/task.h>
#include <system/manager.h>

namespace psy {
namespace menu {
namespace {

engine::State *CreateSplash() {
  engine::State *s = new engine::State;

  // Creating tex and sprite for the splash
  std::shared_ptr<sf::Texture> tex(new sf::Texture);
  std::shared_ptr<sf::Sprite> sprite(new sf::Sprite);
  // Initializing stuff
  tex->loadFromFile("assets/MarvellousSoft.png");
  tex->setSmooth(true);
  sprite->setTexture(*tex);
  sprite->setScale(.62, .62);
  sprite->setPosition(25, 35);

  s->set_render_callback([sprite,tex](sf::RenderWindow &canvas) {
    canvas.draw(*sprite);
  });

  s->AddTask(engine::Task([](const sf::Time& dt) {
    static float sec = 0;
    sec += dt.asSeconds();
    if (sec >= 3) system::ChangeTo(MainMenuState());
  }));

  return s;
}

}  // unnamed namespace

std::shared_ptr<engine::State> SplashState() {
  static const std::shared_ptr<engine::State> splash_state(CreateSplash());
  return splash_state;
}

}  // namespace menu
}  // namespace psy
