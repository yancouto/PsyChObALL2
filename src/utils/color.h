#ifndef PSYCHO2_UTILS_COLOR_H_
#define PSYCHO2_UTILS_COLOR_H_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

namespace psy {
namespace utils {

sf::Color PsychoColor(const sf::Time &time);
sf::Color PsychoColor(const sf::Time &time, sf::Uint8 alpha);

}  // namespace utils
}  // namespace psy

#endif  // PSYCHO2_UTILS_COLOR_H_