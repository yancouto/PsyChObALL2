#include <memory>

#include <system/manager.h>
#include <menu/main_menu.h>
#include <menu/splash_screen.h>

const bool skip_splash = true;

int main() {
  psy::system::Init();
  psy::system::ChangeTo(skip_splash? psy::menu::MainMenuState() : psy::menu::SplashState());
  psy::system::Run();
  psy::system::Release();
  return 0;
}
