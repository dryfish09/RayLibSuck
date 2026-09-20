#include "raylib.h"


void loadFootstepSound() {
    Sound footstep = LoadSound("./assets/sound/walkSound.wav");
}
void playFootstepSound() {
    PlaySound(footstep);
}
void unloadDeclaredSound() {
    UnloadSound(footstep);
}
