#include <utils/math.h>

#include <cmath>

namespace psy {
namespace utils {

namespace math {

int rad_to_deg(double radians) {
  return (360*radians)/(2*M_PI);
}

double deg_to_rad(int degrees) {
  return (2.*M_PI*degrees)/360.;
}

}  // namespace math

}  // namespace utils
}  // namespace psy
