#include <memory>

#include <psycho2.h>
#include <menus/main_menu.h>

int main() {
  psy::system::Init();
  psy::system::ChangeTo(psy::MainMenuScene());
  psy::system::Run();
  psy::system::Release();
  return 0;
}
