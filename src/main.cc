#include <psycho2.h>

int main() {
  psy::system::Init();
  psy::system::Run();
  psy::system::Release();
  return 0;
}
