#include "raylib.h"
#include "./sound.hpp"
#include "./texture.hpp"
#include "./logic.hpp"

int main() {
    // init windows
    InitWindow(windowX, windowY, "Ball's tiny world 2D");
    // init sound:
    InitAudioDevice();
    sound::loadFootstepSound();
    sound::loadRunSound();
    //load texture
    texture::loadTexture();
    // set target fps
    SetTargetFPS(60);
    insertLogic();
    // close sound:
    sound::unloadDeclaredSound();
    // unload texture
    texture::unloadTexture();
    CloseAudioDevice();
    // close windows
    CloseWindow();
    return 0;
}

