#ifndef PSY_UTILS_MATH_H_
#define PSY_UTILS_MATH_H_

namespace psy {
namespace utils {

namespace math {

// Pi for convenience.
extern const double kPi;

// Converts radians to degrees.
int rad_to_deg(double radians);

// Converts degrees to radians.
double deg_to_rad(int degrees);

}  // namespace math

}  // namespace utils
}  // namespace psy

#endif  // PSY_UTILS_MATH_H_