#include <utils/math.h>

#include <cmath>

namespace psy {
namespace utils {

namespace math {

const double kPi = M_PI;

int RadToDeg(double radians) {
  return (180 * radians) / kPi;
}

double DegToRad(int degrees) {
  return (kPi * degrees) / 180.;
}

}  // namespace math

}  // namespace utils
}  // namespace psy
