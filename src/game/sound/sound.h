#pragma once

namespace sound {

    extern Sound footstep;
    extern Sound run;

    void loadFootstepSound();
    void loadRunSound();
    void playRunSound();

    void playFootstepSound();

    void unloadDeclaredSound();
}
