#ifndef PSY_UTILS_COLOR_H_
#define PSY_UTILS_COLOR_H_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

namespace psy {
namespace utils {

// Same color transition as used in PsyChObALL
sf::Color PsychoColor(const sf::Time &time);
sf::Color PsychoColor(const sf::Time &time, sf::Uint8 alpha);

sf::Color TrigoColor(const sf::Time &time);
sf::Color TrigoColor(const sf::Time &time, sf::Uint8 alpha);

}  // namespace utils
}  // namespace psy

#endif  // PSY_UTILS_COLOR_H_