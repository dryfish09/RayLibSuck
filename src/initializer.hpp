#include "rayib.h"
#include "./gvar.hpp"
inline void init() {
    // init windows
    InitWindow(windowX, windowY, "Ball's tiny world 2D");
    // init sound:
    InitAudioDevice();
    sound::loadFootstepSound();
    sound::loadRunSound();
    //load texture
    texture::loadTexture();
}
