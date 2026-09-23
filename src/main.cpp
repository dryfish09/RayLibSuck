#include "raylib.h"
#include "./sound.hpp"
#include "./texture.hpp"
#include "./logic.hpp"

int main() {
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

