//
// This module has everything regarding Scene directly. 
// 
// @see Task
//

#ifndef PSY_ENGINE_SCENE_H_
#define PSY_ENGINE_SCENE_H_

#include "task.h"

#include <functional>
#include <forward_list>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

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
  Scene();
  virtual ~Scene();

  // Method that draws objects into a sf::RenderWindow.
  void Render(const sf::RenderWindow& canvas) const;

  // Method that updates all tasks from this Scene.
  void Update(const sf::Time& dt);

  // Method called once it enters as active Scene.
  virtual void Focus();

  // Method called once it leaves the top of the stack as active Scene.
  virtual void DeFocus();

  // Finishes this Scene.
  void Finish();

  // Sets the current rendering function.
  void set_render_function(
          const std::function<void (const sf::RenderWindow& canvas)>& render) {
    render_function_ = render;
  }

  bool active() const { return active_; }
  bool finished() const { return finished_; }

 private:
  // Whether the Scene is being drawn and updated as active Scene.
  bool active_;
  
  // Whether the scene is to be disabled next frame.
  bool finished_;

  // Rendering callback for drawing.
  std::function<void (const sf::RenderWindow& canvas)> render_function_;

  // A list of tasks to be run by the Scene update method.
  std::forward_list<Task> tasks_;
};

} // namespace psy

#endif
