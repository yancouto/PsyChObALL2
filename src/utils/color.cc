#include <utils/color.h>

#include <cmath>

#include <utils/math.h>

namespace psy {
namespace utils {

sf::Color PsychoColor(const sf::Time &time, sf::Uint8 alpha) {
  static int cycle_time = 10000;
  int t = time.asMilliseconds() % cycle_time;
  double r, g, b;
  const double ct = cycle_time; // much less text
  if (t <= cycle_time / 3) {
    r = 100.;                  // 100%
    g = 100. * t / (ct / 3.);  // 0 -> 100%
    b = 0.;                    // 0%
  } else if (t <= cycle_time / 2) {
    r = 100. * (1. - ((t - ct / 3.) / (ct / 2. - ct / 3.)));  // 100 -> 0%
    g = 100. - 20. * ((t - ct / 3.) / (ct / 2. - ct / 3.));   // 100 -> 80%
    b = 0.;                                                   // 0%
  } else if (t <= 7 * cycle_time / 12) {
    r = 0.;                                                       // 0%
    g = 80. - 20. * ((t - ct / 2.) / (7. * ct / 12. - ct / 2.));  // 80 -> 60%
    b = 60. * ((t - ct / 2.) / (7. * ct / 12. - ct / 2.));        // 0 -> 60%
  } else if (t <= 255 * cycle_time / 360) {
    // 0 -> 11%
    r = 11. * ((t - 7 * ct / 12.) / (255. * ct / 360. - 7. * ct / 12.));
    // 60 -> 11%
    g = 60. - 49. * ((t - 7. * ct / 12.) / (255. * ct / 360. - 7. * ct / 12.)); 
    // 60 -> 70%
    b = 60. + 10. * ((t - 7. * ct / 12.) / (255. * ct / 360. - 7. * ct / 12.)); 
  } else if (t <= 318 * cycle_time / 360) {
    // 11 -> 70%
    r = 11. + 59. * ((t - 255. * ct / 360.) / (318. * ct / 360. - 255. * ct / 360.));
    // 11 -> 0%
    g = 11. * (1. - ((t - 255. * ct / 360.) / (318. * ct / 360. - 255. * ct / 360.)));
    // 70 -> 60%
    b = 70. - 10. * ((t - 255. * ct / 360.) / (318. * ct / 360. - 255. * ct / 360.));
  } else {
    r = 70. + 30. * ((t - 318. * ct / 360.) / (ct - 318. * ct / 360.));   // 70 -> 100%
    g = 0.;                                                               // 0%
    b = 60. * (1. - ((t - 318. * ct / 360.) / (ct - 318. * ct / 360.)));  // 60 -> 0% 
  }

  return sf::Color(r * 2.55, g * 2.55, b * 2.55, alpha);
}

sf::Color PsychoColor(const sf::Time &time) {
  return PsychoColor(time, 255);
}

sf::Color TrigoColor(const sf::Time &time, sf::Uint8 alpha) {
  static int cycle_time = 10000;
  using psy::utils::math::kPi;
  double t = (time.asMilliseconds() % cycle_time) * kPi * 2. / cycle_time;
  double r = (sin(t) + 1) / 2,
         g = (sin(t + 2. * kPi / 3.) + 1) / 2,
         b = (sin(t + 1.2 * kPi) + 1) / 2;
  return sf::Color(r * 255, g * 255, b * 255, alpha);
}

sf::Color TrigoColor(const sf::Time &time) {
  return TrigoColor(time, 255);
}

}  // namespace utils
}  // namespace psy