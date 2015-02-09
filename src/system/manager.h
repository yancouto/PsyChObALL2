#ifndef PSY_SYSTEM_MANAGER_H_
#define PSY_SYSTEM_MANAGER_H_

#include <memory>

#include <SFML/Graphics.hpp>

#include <engine/state.h>
#include <entities/player.h>

namespace psy {
namespace system {

// Initializes all necessary data (Opens the window, etc)
void Init(void);

// Runs the main game loop, exits automatically when window is closed 
void Run(void);

// Releases all data allocated in Init or during the game
void Release(void);

// Changes the current State to state
// Defocus callback is called in the current State
// Focus callback is called in the new State
void ChangeTo(std::shared_ptr<psy::engine::State> state);

}  // namespace system
}  // namespace psy

#endif // PSY_SYSTEM_MANAGER_H_
