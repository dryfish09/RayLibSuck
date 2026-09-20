#pragma once
#include "raylib.h"

namespace sound {

    inline Sound footstep;
    inline Sound run;

    inline void loadFootstepSound() {
        footstep = LoadSound("src/assets/sound/walkSound.wav");
    }
    inline void loadRunSound() {
        run = LoadSound("src/assets/sound/run.wav");
    }
    inline void playRunSound() {
        if (!IsSoundPlaying(run) || !IsSoundPlaying(footstep)) {
            PlaySound(run);
        }
    }

    inline void playFootstepSound() {
        if (!IsSoundPlaying(run) || !IsSoundPlaying(footstep)) {
            PlaySound(footstep);
        }
    }

    inline void unloadDeclaredSound() {
        UnloadSound(footstep);
        UnloadSound(run);
    }

}
