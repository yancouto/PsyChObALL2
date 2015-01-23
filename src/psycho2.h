#ifndef PSYCHO2_PSYCHO2_H_
#define PSYCHO2_PSYCHO2_H_

#include <SFML/Graphics.hpp>

namespace psy {
namespace system {

/* Initializes all necessary data (Opens the window, etc) */
void Init(void);

/* Runs the main game loop, exits automatically when window is closed */
void Run(void);

/* Releases all data allocated in Init or during the game */
void Release(void);

}  // namespace system
}  // namespace psy

#endif // PSYCHO2_PSYCHO2_H_
