#include <memory>

#include <psycho2.h>
#include <engine/scene.h>

int main() {
  psy::system::Init();
  // Empty Scene (Keeps program from closing right away)
  std::shared_ptr<psy::Scene> scene (new psy::Scene);
  psy::system::ChangeTo(scene);
  psy::system::Run();
  psy::system::Release();
  return 0;
}
