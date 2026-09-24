
#include "raylib.h"
#include "game/var.h"
#include "game/sound/sound.h"
#include "game/texture/texture.h"
void init() {
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
void unloadAndClose() {
    // close sound:
    sound::unloadDeclaredSound();
    CloseAudioDevice();
    // unload texture
    texture::unloadTexture();
    texture::unloadBg();
    // close windows
    CloseWindow();
}
