#include <system/globals.h>

#include <SFML/Graphics.hpp>

namespace {

template<typename T> constexpr sf::Vector2<T> CreateVector(T x, T y) {
  return sf::Vector2<T>(x, y);
}

}  // unnamed namespace

namespace psy {
namespace system {

sf::Vector2<double> mouse_position {0, 0};
sf::Vector2<int>    window_size    {1024, 768};

sf::Vector2<int>    desktop_resolution = CreateVector<int>(
  sf::VideoMode::getDesktopMode().width, 
  sf::VideoMode::getDesktopMode().height);

}  // namespace system
}  // namespace psy
