#pragma once
#include "raylib.h"
namespace texture {
    Texture2D flowerTexture;
    Texture2D bg;
    void drawBackground(Texture2D tex);
    void loadTexture();
    void loadBg();
    void unloadBg();
    void unloadTexture();
} // namespace
