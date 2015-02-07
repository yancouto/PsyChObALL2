#include <engine/task.h>

#include <functional>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

namespace psy {
namespace engine {

// Warning: This should NOT be called.
Task::Task() : finished_(false) {}
 
Task::Task(const std::function<void (const sf::Time &dt)> &func) : 
      update_function_(func), 
      finished_(false) {}

Task::~Task() {}

void Task::Update(const sf::Time &dt) {
  update_function_(dt);
}

}  // namespace engine
}  // namespace psy
