#ifndef PSY_MENU_SPLASH_SCREEN_H_
#define PSY_MENU_SPLASH_SCREEN_H_

#include <memory>

#include <engine/state.h>

namespace psy {
namespace menu {

std::shared_ptr<engine::State> SplashState(void);

}  // namespace menu
}  // namespace psy

#endif  // PSY_MENU_SPLASH_SCREEN_H_