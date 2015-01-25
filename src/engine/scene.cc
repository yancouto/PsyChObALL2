#include "scene.h"
#include "task.h"

#include <algorithm>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace psy {

Scene::Scene() : active_(false), finished_(false) {}

Scene::~Scene() {}

// We need to see whether the Scene is actually running.
void Scene::Render(sf::RenderWindow &canvas) const {
  if (active_ && !finished_ && render_callback_) render_callback_(canvas);
}

// Checks whether the current task is to be destroyed next frame.
namespace {
bool task_finished(Task &current_task) {
  return current_task.finished();
}
}  // namespace

// If the Scene is inactive or is set to finish, we do not update.
void Scene::Update(const sf::Time &dt) {
  if (!active_ || finished_) return;

  for(auto it = tasks_.begin(); it != tasks_.end(); ++it)
    it->Update(dt);
  
  std::remove_if(tasks_.begin(), tasks_.end(), task_finished);
}

void Scene::Focus() {
  active_ = true;
  if(focus_callback_) focus_callback_(*this);
}

void Scene::DeFocus() {
  active_ = false;
  if(defocus_callback_) defocus_callback_(*this);
}

void Scene::Finish() {
  finished_ = true;
}

}  // namespace psy
