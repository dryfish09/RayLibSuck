#include "sound.h"
#include "raylib.h"

namespace sound {
    Music bgm;
    Sound footstep;
    Sound run;

    void loadFootstepSound() {
        footstep = LoadSound("src/assets/sound/walkSound.wav");
    }
    void loadRunSound() {
        run = LoadSound("src/assets/sound/run.wav");
    }
    void loadBgm() {
        bgm = LoadMusicStream("src/assets/sound/bgm.mp3");
    void playRunSound() {
        if (!IsSoundPlaying(run) && !IsSoundPlaying(footstep)) {
            PlaySound(run);
        }
    }
    void playBgm() {
        PlayMusicStream(bgm);
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
    void unloadBgm() {
        UnloadMusicStream(bgm);
    }
}
