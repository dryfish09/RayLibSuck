#pragma once
#include "raylib.h"
namespace texture {
    extern Texture2D flowerTexture;
    extern Texture2D bg;
    void drawBackground(Texture2D tex);
    void loadTexture();
    void loadBg();
    void unloadBg();
    void unloadTexture();
} // namespace
