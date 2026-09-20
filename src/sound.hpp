#include "raylib"


void loadFootstepSound() {
    Sound footstep = LoadSound("./assets/sound/walkSound.wav");
}
void unloadDeclaredSound() {
    UnloadSound(footstep);
}
