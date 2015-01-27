#include <memory>

#include <system/psycho2.h>
#include <menu/main_menu.h>

int main() {
  psy::system::Init();
  psy::system::ChangeTo(psy::menu::MainMenuScene());
  psy::system::Run();
  psy::system::Release();
  return 0;
}
