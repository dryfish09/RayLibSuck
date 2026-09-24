
#include "raylib.h"

namespace sound {

    Sound footstep;
    Sound run;

    void loadFootstepSound() {
        footstep = LoadSound("src/assets/sound/walkSound.wav");
    }
    void loadRunSound() {
        run = LoadSound("src/assets/sound/run.wav");
    }
    void playRunSound() {
        if (!IsSoundPlaying(run) && !IsSoundPlaying(footstep)) {
            PlaySound(run);
        }
    }

    void playFootstepSound() {
        if (!IsSoundPlaying(run) && !IsSoundPlaying(footstep)) {
            PlaySound(footstep);
        }
    }

    void unloadDeclaredSound() {
        UnloadSound(footstep);
        UnloadSound(run);
    }

}
