#include <utils/math.h>

#include <cmath>

namespace psy {
namespace utils {

namespace math {

const double kPi = M_PI;

int rad_to_deg(double radians) {
  return (360*radians)/(2*kPi);
}

double deg_to_rad(int degrees) {
  return (2.*kPi*degrees)/360.;
}

}  // namespace math

}  // namespace utils
}  // namespace psy
