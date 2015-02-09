#include <memory>

#include <system/manager.h>
#include <menu/main_menu.h>

int main() {
  psy::system::Init();
  psy::system::ChangeTo(psy::menu::MainMenuState());
  psy::system::Run();
  psy::system::Release();
  return 0;
}
