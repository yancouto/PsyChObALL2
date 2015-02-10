#ifndef PSY_UTILS_COLOR_H_
#define PSY_UTILS_COLOR_H_

#include <functional>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

namespace psy {
namespace utils {

using ColorFunctionRaw = sf::Color (*)(const sf::Time&, sf::Uint8);
using ColorFunction = std::function<sf::Color (const sf::Time&, sf::Uint8)>;

// Same color transition as used in PsyChObALL
sf::Color PsychoColor(const sf::Time &time);
sf::Color PsychoColor(const sf::Time &time, sf::Uint8 alpha);

sf::Color TrigoColor(const sf::Time &time);
sf::Color TrigoColor(const sf::Time &time, sf::Uint8 alpha);

class ColorPattern {
 public:
  explicit ColorPattern(ColorFunction func);
  ColorPattern(void);

  sf::Color CurrentColor(sf::Uint8 alpha) {
    return color_func_(clock_.getElapsedTime(), alpha);
  }
  sf::Color CurrentColor(void) { return CurrentColor(255); }

  ColorFunction color_func(void) { return color_func_; }
  void set_color_func(ColorFunction func) { color_func_ = func; }
 private:
  ColorFunction color_func_;
  sf::Clock clock_;
};

}  // namespace utils
}  // namespace psy

#endif  // PSY_UTILS_COLOR_H_