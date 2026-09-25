#pragma once

namespace sound {

    extern Sound footstep;
    extern Sound run;
    extern Music bgm;

    void loadFootstepSound();
    void loadBgm();
    void loadRunSound();
    void playRunSound();
    void playBgm();
    void playFootstepSound();
    void unloadBgm();
    void unloadDeclaredSound();
}
