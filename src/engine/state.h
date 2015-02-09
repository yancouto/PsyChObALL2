// This module has everything regarding State directly. 
// @see Task

#ifndef PSY_ENGINE_STATE_H_
#define PSY_ENGINE_STATE_H_

#include <forward_list>
#include <functional>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <engine/task.h>

namespace psy {
namespace engine {

// A State is a class designed to manage all Tasks and renderable elements 
// that are supposed to be active at the same time.
//
// There can exist multiple States. However there must only be one State
// active at a time.
//
// It is conventional for a stack to be the appropriate data structure
// to be used for storing States.
//
// Inspired by UGDK's Scene:
//   https://www.github.com/uspgamedev/ugdk/
class State {
 public:
  typedef std::function<void (sf::RenderWindow &canvas)> RenderCallback;
  typedef std::function<void (psy::engine::State &self)> StateCallback;

  State();
  virtual ~State();

  // Method that draws objects into a sf::RenderWindow.
  void Render(sf::RenderWindow &canvas) const;

  // Method that updates all tasks from this State.
  void Update(const sf::Time &dt);

  // Method called once it enters as active State.
  void Focus();

  // Method called once it leaves the top of the stack as active State.
  void DeFocus();

  // Finishes this State.
  void Finish();

  // Adds a task to the State.
  void AddTask(const Task &task) {
    tasks_.push_front(task);
  }

  // Sets the current rendering function.
  void set_render_callback(const RenderCallback &render) {
    render_callback_ = render;
  }

  // Sets the current focus callback function.
  void set_focus_callback(const StateCallback &focus) {
    focus_callback_ = focus;
  }

  // Sets the current defocus callback function.
  void set_defocus_callback(const StateCallback &defocus) {
    defocus_callback_ = defocus;
  }

  bool active() const { return active_; }
  bool finished() const { return finished_; }

 private:
  // Whether the State is being drawn and updated as active State.
  bool active_;
  
  // Whether the state is to be disabled next frame.
  bool finished_;

  // Rendering callback for drawing.
  RenderCallback render_callback_;

  // Functions called when State becomes active and unactive.
  StateCallback focus_callback_, defocus_callback_;

  // A list of tasks to be run by the State update method.
  std::forward_list<Task> tasks_;
};

}  // namespace engine
}  // namespace psy

#endif  // PSY_ENGINE_STATE_H_
