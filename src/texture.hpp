#pragma once
#include "raylib.h"
namespace texture {
    inline Texture2D flowerTexture;
    inline void loadTexture() {
        flowerTexture = LoadTexture("src/assets/texture/flower.png");
    }
    inline void unloadTexture() {
        UnloadTexture(flowerTexture);
    }
} // namespace
