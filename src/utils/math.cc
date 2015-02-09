#include <utils/math.h>

#include <cmath>

namespace psy {
namespace utils {

namespace math {

const double kPi = M_PI;

int RadToDeg(double radians) {
  return (360 * radians) / (2 * kPi);
}

double DegToRad(int degrees) {
  return (2. * kPi * degrees) / 360.;
}

}  // namespace math

}  // namespace utils
}  // namespace psy
