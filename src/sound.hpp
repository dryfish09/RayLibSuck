#pragma once
#include "raylib.h"

namespace sound {

    inline Sound footstep;

    inline void loadFootstepSound() {
        footstep = LoadSound("src/assets/sound/walkSound.wav");
    }

    inline void playFootstepSound() {
        PlaySound(footstep);
    }

    inline void unloadDeclaredSound() {
        UnloadSound(footstep);
    }

}
