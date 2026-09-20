#include "raylib"
#include <string>

void loadFootstepSound() {
    Sound footstep = LoadSound("./assets/sound/walkSound.wav");
}
void unloadAllDeclaredSound() {
    UnloadSound(footstep);
}
