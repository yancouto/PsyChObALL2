//
// This module has everything regarding Scene directly. 
// 
// @see Task
//

#ifndef PSYCHO2_ENGINE_SCENE_H_
#define PSYCHO2_ENGINE_SCENE_H_

#include <functional>
#include <forward_list>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <engine/task.h>

namespace psy {

// A Scene is a class designed to manage all Tasks and renderable elements 
// that are supposed to be active at the same time.
//
// There can exist multiple Scenes. However there must only be one Scene
// active at a time.
//
// It is conventional for a stack to be the appropriate data structure
// to be used for storing Scenes.
//
// Inspired by UGDK's Scene:
//   https://www.github.com/uspgamedev/ugdk/
class Scene {
 public:
  typedef std::function<void (sf::RenderWindow &canvas)> RenderCallback;
  typedef std::function<void (const psy::Scene &scene)> SceneCallback;

  Scene();
  virtual ~Scene();

  // Method that draws objects into a sf::RenderWindow.
  void Render(sf::RenderWindow &canvas) const;

  // Method that updates all tasks from this Scene.
  void Update(const sf::Time &dt);

  // Method called once it enters as active Scene.
  void Focus();

  // Method called once it leaves the top of the stack as active Scene.
  void DeFocus();

  // Finishes this Scene.
  void Finish();

  // Adds a task to the Scene.
  void AddTask(const Task &task) {
    tasks_.push_front(task);
  }

  // Sets the current rendering function.
  void set_render_callback(const RenderCallback &render) {
    render_callback_ = render;
  }

  // Sets the current focus callback function.
  void set_focus_callback(const SceneCallback &focus) {
    focus_callback_ = focus;
  }

  // Sets the current defocus callback function.
  void set_defocus_callback(const SceneCallback &defocus) {
    defocus_callback_ = defocus;
  }

  bool active() const { return active_; }
  bool finished() const { return finished_; }

 private:
  // Whether the Scene is being drawn and updated as active Scene.
  bool active_;
  
  // Whether the scene is to be disabled next frame.
  bool finished_;

  // Rendering callback for drawing.
  RenderCallback render_callback_;

  // Functions called when Scene becomes active and unactive.
  SceneCallback focus_callback_, defocus_callback_;

  // A list of tasks to be run by the Scene update method.
  std::forward_list<Task> tasks_;
};

}  // namespace psy

#endif  // PSYCHO2_ENGINE_SCENE_H_
