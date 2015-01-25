#ifndef PSYCHO2_PSYCHO2_H_
#define PSYCHO2_PSYCHO2_H_

#include <memory>

#include <SFML/Graphics.hpp>

#include <engine/scene.h>

namespace psy {
namespace system {

// Initializes all necessary data (Opens the window, etc)
void Init(void);

// Runs the main game loop, exits automatically when window is closed 
void Run(void);

// Releases all data allocated in Init or during the game
void Release(void);

// Changes the current Scene to scene
// Defocus callback is called in the current Scene
// Focus callback is called in the new Scene
void ChangeTo(std::shared_ptr<psy::Scene> scene);

}  // namespace system
}  // namespace psy

#endif // PSYCHO2_PSYCHO2_H_
