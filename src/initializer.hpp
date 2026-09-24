#pragma once
#include "raylib.h"
#include "./gvar.hpp"
#include "./sound.hpp"
#include "./texture.hpp"
inline void init() {
    // init windows
    InitWindow(windowX, windowY, "Ball's tiny world 2D");
    // init sound:
    InitAudioDevice();
    sound::loadFootstepSound();
    sound::loadRunSound();
    //load texture
    texture::loadBg();
    texture::loadTexture();
}
inline void unloadAndClose() {
    // close sound:
    sound::unloadDeclaredSound();
    CloseAudioDevice();
    // unload texture
    texture::unloadTexture();
    // close windows
    CloseWindow();
}
